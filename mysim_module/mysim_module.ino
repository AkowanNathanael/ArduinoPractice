#include <SoftwareSerial.h>

SoftwareSerial SIM800L(2, 3); // RX, TX
int LED = 13;

void setup() {
  Serial.begin(9600);
  SIM800L.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("Setup complete.");
}

void loop() {
  // Check if there is a message from the SIM800L module.
  if (SIM800L.available()) {
    // Read the message from the SIM800L module.
    String message = SIM800L.readStringUntil('\n');

    // Trim leading and trailing whitespace from the message.
    message.trim();

    // Print the received message to the Serial Monitor.
    Serial.println("Received message: " + message);

    // Process the received message.
    if (message == "ON") {
      digitalWrite(LED, HIGH); // Turn on the LED
      Serial.println("LED turned ON");
    } else if (message == "OFF") {
      digitalWrite(LED, LOW); // Turn off the LED
      Serial.println("LED turned OFF");
    } else if (message == "CALL") {
      // Make a call to the phone number "+233546878947"
      Serial.println("Making a call...");
      SIM800L.println("ATD+233546878947;");
      delay(10000); // Wait for 10 seconds (adjust as needed)
      SIM800L.println("ATH"); // End the call
    } else if (message == "SMS") {
      // Send an SMS message to the phone number "+233546878947"
      Serial.println("Sending SMS...");
      SIM800L.println("AT+CMGF=1"); // Set SMS text mode
      delay(1000);
      SIM800L.println("AT+CMGS=\"+233546878947\"");
      delay(1000);
      SIM800L.println("This is the message that I want to send.");
      delay(1000);
      SIM800L.write(0x1A); // Send Ctrl+Z to end the SMS
    }
  }
}
