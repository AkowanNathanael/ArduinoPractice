int c=8;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
//pinMode();

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(8));

}
