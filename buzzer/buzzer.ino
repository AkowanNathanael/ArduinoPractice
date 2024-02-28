int buzzer=6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("start");
  digitalWrite(buzzer,HIGH);
  delay(1000);
  digitalWrite(buzzer,LOW);
  delay(1000);
  Serial.println("end");

}
