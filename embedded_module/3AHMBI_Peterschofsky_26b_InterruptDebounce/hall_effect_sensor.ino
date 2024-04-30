

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





int led = 13; // LED on Arduino
int digitalPin = 4; // Linear Hall magnetic sensor digital interface
int analogPin = 2; // Linear Hall magnetic sensor analog interface
int digitalVal; // Digital readings
int analogVal; // Analog readings
int lastDigitalVal = -1; // Stores the last digital value read

void setup() {
  pinMode(led, OUTPUT);
  pinMode(digitalPin, INPUT);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the digital interface
  digitalVal = digitalRead(digitalPin);

  // When magnetic field is present, Arduino LED is on
  digitalWrite(led, digitalVal == HIGH ? HIGH : LOW);

  // Only print the digital value if it has changed
  if (digitalVal != lastDigitalVal) {
    Serial.println(digitalVal);
    lastDigitalVal = digitalVal; // Update the lastDigitalVal
  }

  // Read the analog interface
  analogVal = analogRead(analogPin);

  delay(1); // Small delay to stabilize readings
}







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