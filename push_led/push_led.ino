const int buttonPin = 2;   // Pin connected to the push button
const int ledPin = 13;     // Pin connected to the LED
bool ledState = false;     // Variable to store the LED state
bool buttonState = false;  // Variable to store the button state
bool lastButtonState = false;  // Variable to store the previous button state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Set the button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);  
  Serial.begin(115200);// Set the LED pin as output
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read the state of the button

  // Check if the button state has changed
  if (buttonState != lastButtonState) {
    // If the button is pressed (LOW state)
    if (buttonState == LOW) {
      ledState = !ledState;  // Toggle the LED state
      digitalWrite(ledPin, ledState);  // Set the LED pin accordingly
      Serial.println(buttonState);
    }
    delay(50);  // Debounce delay to avoid false triggering
  }

  lastButtonState = buttonState;  // Update the previous button state
}
