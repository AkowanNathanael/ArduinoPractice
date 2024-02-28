#include <SoftwareSerial.h>

// Define the SoftwareSerial object to communicate with the SIM800L
SoftwareSerial sim800l(2, 3); // RX, TX (connect these to the corresponding pins on the SIM800L module)

void setup() {
  // Start the serial communication for debugging
  Serial.begin(9600);
  
  // Start the SoftwareSerial communication with the SIM800L module
  sim800l.begin(9600);
  
  delay(1000); // Give the module time to initialize
  
  // Enable caller ID notification
  sim800l.println("AT+CLIP=1");
}

void loop() {
  // Check for an incoming call
  if (sim800l.available()) {
    String response = sim800l.readString();
    Serial.println(response);
  }
}
