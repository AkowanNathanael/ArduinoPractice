int relay=10;
void setup() {
  pinMode(OUTPUT,relay);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay,1);
  delay(2000);
  digitalWrite(relay,0);
  delay(2000);
  

}
