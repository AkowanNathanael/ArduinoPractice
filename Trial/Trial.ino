//int led=13;
//int photo=A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorData=analogRead(A1);
  Serial.println(sensorData);
  if(sensorData>=300){
    digitalWrite(13,HIGH);
  }else {
    digitalWrite(13,LOW);
  }
  delay(200);
}
