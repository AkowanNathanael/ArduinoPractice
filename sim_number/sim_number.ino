#include <SoftwareSerial.h>

// Define the SoftwareSerial object to communicate with the SIM800L
SoftwareSerial sim800l(2, 3); // RX, TX (connect these to the corresponding pins on the SIM800L module)

void setup() {
  // Start the serial communication for debugging
  Serial.begin(9600);
  
  // Start the SoftwareSerial communication with the SIM800L module
  sim800l.begin(9600);
  
  delay(1000); // Give the module time to initialize
}

void loop() {
  // Send AT command to check if the SIM800L module is responsive
  sim800l.println("AT");
  
  // Wait for a response from the module
  while (sim800l.available()) {
    char c = sim800l.read();
    Serial.write(c);
  }
  
  // Send AT command to retrieve the SIM card's phone number
  sim800l.println("AT+CNUM");
  
  // Wait for a response from the module
  String response = "";
  while (sim800l.available()) {
    char c = sim800l.read();
    response += c;
  }
  
  // Check if the response contains the phone number
  if (response.indexOf("+CNUM:") != -1) {
    int commaIndex = response.indexOf(",");
    if (commaIndex != -1) {
      // Extract and print the phone number
      String phoneNumber = response.substring(commaIndex + 2); // Skip the comma and space
      Serial.print("SIM Card Phone Number: ");
      Serial.println(phoneNumber);
    }
  } else {
    Serial.println("Unable to retrieve phone number.");
  }
  
  delay(5000); // Delay before repeating
}
