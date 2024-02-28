
int relay=230;
void setup() {
//  pinMode(relay, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(relay, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(relay, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
}
