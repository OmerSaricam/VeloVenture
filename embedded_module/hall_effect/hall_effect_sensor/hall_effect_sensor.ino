

int led = 13; // LED on Arduino
int digitalPin = 4; // Linear Hall magnetic sensor digital interface
int lastDigitalVal = LOW; // Stores the last digital value read
unsigned long lastCheck = 0; // Last time the speed was checked
float wheelCircumference = 1.75; // Wheel circumference in meters
float distancePerMagnet = wheelCircumference / 3; // Distance per magnet pass
const long interval = 2000; // Interval to check speed in milliseconds
int magnetCount = 0; // Count of magnet passes

void setup() {
  pinMode(led, OUTPUT);
  pinMode(digitalPin, INPUT);
  Serial.begin(9600);
  lastCheck = millis(); // Initialize last check time
}

void loop() {
  int digitalVal = digitalRead(digitalPin); // Read the current state of the magnetic sensor

  // Check for rising edge
  if (digitalVal == HIGH && lastDigitalVal == LOW) {
    magnetCount++; // Increment magnet pass count
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

    // Print the speed
    Serial.print("Speed: ");
    Serial.print(speedMS);
    Serial.print(" m/s, ");
    Serial.print(speedKMH);
    Serial.println(" km/h");

    // Reset for next interval
    magnetCount = 0;
    lastCheck = currentTime;
  }

  delay(1); // Short delay to stabilize readings
}









// int led = 13; // LED on Arduino
// int digitalPin = 4; // Linear Hall magnetic sensor digital interface
// int analogPin = 2; // Linear Hall magnetic sensor analog interface
// int digitalVal; // Digital readings
// int lastDigitalVal = -1; // Stores the last digital value read
// unsigned long lastTime = 0; // Time of the last detected "1"
// unsigned long lastPrintTime = 0; // Time of the last speed print
// int count = 0; // Count of consecutive "1"s
// float wheelCircumference = 1.75; // Wheel circumference in meters
// const long interval = 2000; // Check interval in milliseconds (2 seconds)

// void setup() {
//   pinMode(led, OUTPUT);
//   pinMode(digitalPin, INPUT);
//   pinMode(analogPin, INPUT);
//   Serial.begin(9600);
//   lastPrintTime = millis(); // Initialize last print time
// }

// void loop() {
//   unsigned long currentTime = millis(); // Update current time
//   digitalVal = digitalRead(digitalPin);
//   digitalWrite(led, digitalVal == HIGH ? HIGH : LOW);

//   if (digitalVal == HIGH && lastDigitalVal == LOW) {
//     if (count == 0) {
//       lastTime = currentTime; // Reset the timer on the first count
//     }
//     count++;
//     Serial.print("1 ");
//     if (count == 3) {
//       float elapsedTime = (currentTime - lastTime) / 1000.0;
//       float speedMS = wheelCircumference / elapsedTime; // Speed in meters per second
//       float speedKMH = speedMS * 3.6; // Convert m/s to km/h
//       Serial.print("Speed: ");
//       Serial.print(speedMS);
//       Serial.print(" m/s, ");
//       Serial.print(speedKMH);
//       Serial.println(" km/h");
//       count = 0;
//     }
//   }

//   // Print speed every interval or if no '1' detected
//   if (currentTime - lastPrintTime >= interval) {
//     if (count == 0) { // No '1' detected within the interval
//       Serial.println("Speed: 0 m/s, 0 km/h");
//     }
//     lastPrintTime = currentTime; // Reset the last print time
//   }

//   lastDigitalVal = digitalVal;
//   delay(1); // Small delay to stabilize readings
// }






// int led = 13; // LED on Arduino
// int digitalPin = 4; // Linear Hall magnetic sensor digital interface
// int analogPin = 2; // Linear Hall magnetic sensor analog interface
// int digitalVal; // Digital readings
// int analogVal; // Analog readings
// int lastDigitalVal = -1; // Stores the last digital value read
// unsigned long lastTime = 0; // Time of the last detected "1"
// int count = 0; // Count of consecutive "1"s
// float wheelCircumference = 1.75; // Wheel circumference in meters

// void setup() {
//   pinMode(led, OUTPUT);
//   pinMode(digitalPin, INPUT);
//   pinMode(analogPin, INPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   // Read the digital interface
//   digitalVal = digitalRead(digitalPin);
//   digitalWrite(led, digitalVal == HIGH ? HIGH : LOW);

//   // Check for rising edge
//   if (digitalVal == HIGH && lastDigitalVal == LOW) {
//     if (count == 0) {
//       // Reset the timer on the first count
//       lastTime = millis();
//     }
//     count++;
//     Serial.print("1 ");
//     if (count == 3) {
//       // Calculate elapsed time in seconds
//       float elapsedTime = (millis() - lastTime) / 1000.0;
//       float speedMS = wheelCircumference / elapsedTime; // Speed in meters per second
//       float speedKMH = speedMS * 3.6; // Convert m/s to km/h
//       Serial.print("Speed: ");
//       Serial.print(speedMS);
//       Serial.print(" m/s, ");
//       Serial.print(speedKMH);
//       Serial.println(" km/h");
//       count = 0; // Reset count after one full revolution
//     }
//   }

//   // Update lastDigitalVal
//   lastDigitalVal = digitalVal;
//   delay(1); // Small delay to stabilize readings
// }





// int led = 13; // LED on Arduino
// int digitalPin = 4; // Linear Hall magnetic sensor digital interface
// int analogPin = 2; // Linear Hall magnetic sensor analog interface
// int digitalVal; // Digital readings
// int analogVal; // Analog readings
// int lastDigitalVal = -1; // Stores the last digital value read

// void setup() {
//   pinMode(led, OUTPUT);
//   pinMode(digitalPin, INPUT);
//   pinMode(analogPin, INPUT);
//   Serial.begin(9600);
// }

// void loop() {
//   // Read the digital interface
//   digitalVal = digitalRead(digitalPin);

//   // When magnetic field is present, Arduino LED is on
//   digitalWrite(led, digitalVal == HIGH ? HIGH : LOW);

//   // Only print the digital value if it has changed
//   if (digitalVal != lastDigitalVal) {
//     Serial.println(digitalVal);
//     lastDigitalVal = digitalVal; // Update the lastDigitalVal
//   }

//   // Read the analog interface
//   analogVal = analogRead(analogPin);

//   delay(1); // Small delay to stabilize readings
// }










// int led = 13; // LED on Arduino
// int digitalPin = 4; // Linear Hall magnetic sensor digital interface
// int digitalVal; // Digital readings
// bool lastDigitalVal = LOW; // Last digital value read
// unsigned long lastDebounceTime = 0; // Last time the output pin was toggled
// unsigned long debounceDelay = 50; // Debounce delay in milliseconds

// void setup() {
//   pinMode(led, OUTPUT);
//   pinMode(digitalPin, INPUT);
//   Serial.begin(115200);
// }

// void loop() {
//   int reading = digitalRead(digitalPin);

//   // Check if the input has changed
//   if (reading != lastDigitalVal) {
//     lastDebounceTime = millis();
//   }

//   if ((millis() - lastDebounceTime) > debounceDelay) {
//     // Update the actual value if the reading has been stable for longer than the debounceDelay
//     if (reading != digitalVal) {
//       digitalVal = reading;
//       digitalWrite(led, digitalVal); // Set LED based on digital value
//       Serial.println(digitalVal); // Print digital value
//     }
//   }

//   lastDigitalVal = reading; // Save the reading for next time
// }










// int led = 13 ; // LED on arduino
// int digitalPin = 4; // linear Hall magnetic sensor digital interface
// int analogPin = 2 ;// linear Hall magnetic sensor analog interface
// int digitalVal ; // digital readings
// int analogVal; // analog readings

// void setup ()
// {
//   pinMode (led, OUTPUT); 
//   pinMode (digitalPin, INPUT); 
//   pinMode(analogPin, INPUT); 
//   Serial.begin(9600);
// }

// void loop ()
// {
//   // Read the digital interface
//   digitalVal = digitalRead(digitalPin) ; 
//   if (digitalVal == HIGH) // When magnetic field is present, Arduino LED is on
//   {
//     digitalWrite (led, HIGH);
//   }
//   else
//   {
//     digitalWrite (led, LOW);
//   }
  
//   // Read the analog interface
//   analogVal = analogRead(analogPin);
//   if(digitalVal == 1){
//     Serial.println(digitalVal); // print analog value
//   }

//   delay(1);
// }