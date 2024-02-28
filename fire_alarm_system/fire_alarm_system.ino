int buzzer=6;
int flame=A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int flameVal=analogRead(flame);
  Serial.println(flameVal);
  if (flameVal <1000){
    digitalWrite(buzzer,HIGH);
    delay(1000);
  }else{
    digitalWrite(buzzer,LOW);
    delay(1000);
  }
}
