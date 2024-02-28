int nbuz=6;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//  tone(nbuz,1000);
  for (int i=0;i<1023; i++){
    tone(nbuz,i);
    delay(30);
    Serial.println(i);
  }

}
