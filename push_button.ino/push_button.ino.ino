const int buttonPin = 8;   // Pin for the push button
const int ledPin = 13;     // Pin for the LED

bool ledOn = false;        // State of the LED

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(buttonPin)) {
    ledOn = !ledOn;
    digitalWrite(ledPin, ledOn);
  }
  Serial.println(digitalRead(buttonPin));
  delay(10);  // Small delay to reduce processing load
}
