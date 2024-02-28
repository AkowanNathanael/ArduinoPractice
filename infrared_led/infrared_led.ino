//int infrared1=9;
int infrared2=8;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(infrared2, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("infrared!");
//  Serial.println(digitalRead(infrared1));
  Serial.println(digitalRead(infrared2));
  if(digitalRead(infrared2)==0){
    digitalWrite(13,1);
  }else{
     digitalWrite(13,0);
    }
  delay(300);
}
