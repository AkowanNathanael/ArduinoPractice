int flame=A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int flameVal=analogRead(flame);
  Serial.println(flameVal);

}
