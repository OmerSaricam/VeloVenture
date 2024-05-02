#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
int servoPin = 18;  // GPIO pin for servo control
unsigned long lastInputTime = 0;  // Debounce timer

void setup() {
  myservo.attach(servoPin);  // attaches the servo on GPIO 18 to the servo object
  Serial.begin(9600);  // start serial communication at 115200 baud
  while (!Serial);  // wait for the serial port to connect
  Serial.println("Enter angle (0-360):");
}

void loop() {
  if (Serial.available() > 0) {
    unsigned long currentTime = millis();
    if (currentTime - lastInputTime > 200) {  // Simple debounce check
      int angle = Serial.parseInt();  // read the next available integer
      if (angle >= 180 && angle <= 360) {
        myservo.write(map(angle, 0, 360, 0, 180));  // map 360 degrees to 180 degrees servo range
        Serial.print("Servo moved to: ");
        Serial.println(angle);
      } else {
        Serial.println("Invalid angle. Please enter a value between 0 and 360.");
      }
      Serial.println("Enter next angle (0-360):");
      lastInputTime = currentTime;  // Reset debounce timer
    }
    while (Serial.available() > 0) Serial.read();  // Clear any remaining input
  }
}
