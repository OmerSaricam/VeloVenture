/* 
  Rotary Encoder Sensor and Hall effect combined reading code for ESP-32 (arduino compatible)
*/

#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
int servoPin = 2;  // GPIO pin for servo control
unsigned long lastInputTime = 0;  // Debounce timer

int led = 13; // LED on Arduino
int digitalPin = 4; // Linear Hall magnetic sensor digital interface
int lastDigitalVal = LOW; // Stores the last digital value read
unsigned long lastCheck = 0; // Last time the speed was checked
float wheelCircumference = 1.75; // Wheel circumference in meters
float distancePerMagnet = wheelCircumference / 3; // Distance per magnet pass
const long interval = 1000; // Interval to check speed in milliseconds
int magnetCount = 0; // Count of magnet passes

// Rotary Encoder Inputs
#define CLK 21
#define DT 19
#define SW 18

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir ="";
unsigned long lastButtonPress = 0;

void setup() {
  
  myservo.attach(servoPin);  // attaches the servo on GPIO 18 to the servo object
  Serial.begin(9600);

  pinMode(led, OUTPUT);
  // Set hall effect pin
  pinMode(digitalPin, INPUT);

  // Set encoder pins
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);

  lastStateCLK = digitalRead(CLK);
  Serial.println("Enter angle (180-360):");
}

void loop() {
  handleMagneticSensor();
  handleRotaryEncoder();
  handleServoControl();
  delay(1);
}

void handleMagneticSensor() {
  int digitalVal = digitalRead(digitalPin);

  if (digitalVal == HIGH && lastDigitalVal == LOW) {
    magnetCount++;
    digitalWrite(led, HIGH); // Turn on LED
  } else {
    digitalWrite(led, LOW); // Turn off LED
  }

  lastDigitalVal = digitalVal; // Update the last digital value

    // Check if it is time to calculate speed
  unsigned long currentTime = millis();
  if (currentTime - lastCheck >= interval) {
    float distance = magnetCount * distancePerMagnet; // Total distance covered
    float timeSeconds = (currentTime - lastCheck) / 1000.0; // Time in seconds
    float speedMS = distance / timeSeconds; // Speed in meters per second
    float speedKMH = speedMS * 3.6; // Speed in kilometers per hour

    printSpeed(speedMS, speedKMH);

    // Reset for next interval
    magnetCount = 0;
    lastCheck = currentTime;
  }

}

void handleRotaryEncoder() {
  // Read the current state of CLK
	currentStateCLK = digitalRead(CLK);

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	if (currentStateCLK != lastStateCLK  && currentStateCLK == 1){

		// If the DT state is different than the CLK state then
		// the encoder is rotating CCW so decrement
		if (digitalRead(DT) != currentStateCLK) {
			counter --;
			currentDir ="CCW";
		} else {
			// Encoder is rotating CW so increment
			counter ++;
			currentDir ="CW";
		}

		Serial.print("Direction: ");
		Serial.print(currentDir);
		Serial.print(" | Counter: ");
		Serial.println(counter);
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;

  // Read the button state
  int btnState = digitalRead(SW);

  //If we detect LOW signal, button is pressed
	if (btnState == LOW) {
		//if 50ms have passed since last LOW pulse, it means that the
		//button has been pressed, released and pressed again
		if (millis() - lastButtonPress > 50) {
			Serial.println("Button pressed!");
		}
		// Remember last button press event
		lastButtonPress = millis();
	}
}
void handleServoControl() {
  if (Serial.available() > 0) {
    unsigned long currentTime = millis();
    if (currentTime - lastInputTime > 200) {  // Simple debounce check
      int angle = Serial.parseInt();  // read the next available integer
      if (angle >= 180 && angle <= 360) {
        myservo.write(map(angle, 0, 360, 0, 180));  // map 360 degrees to 180 degrees servo range
        Serial.print("Servo moved to: ");
        Serial.println(angle);
      } else {
        Serial.println("Invalid angle. Please enter a value between 180 and 360.");
      }
      Serial.println("Enter next angle (180-360):");
      lastInputTime = currentTime;  // Reset debounce timer
    }
    while (Serial.available() > 0) Serial.read();  // Clear any remaining input
  }
}

void printSpeed(float speedMS, float speedKMH) {
  Serial.print("Speed: ");
  Serial.print(speedMS);
  Serial.print(" m/s, ");
  Serial.print(speedKMH);
  Serial.println(" km/h");
}