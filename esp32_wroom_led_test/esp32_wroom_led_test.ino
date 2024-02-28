int led=2;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
// pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2,HIGH); //pin 2 is led built in default for esp32
  delay(200);
  digitalWrite(2,LOW);
  Serial.print("Hall:  ");
  Serial.println(hallRead());
    Serial.print("Touch:  ");
  Serial.println(touchRead(T0)); //touch pin is T0 which is GPIO 4

}
