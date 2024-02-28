//#define x A0
int x;
#define led 11
//#define y A1
int y;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    x=map(analogRead(x),0,1023,1,101);
    y=map(analogRead(y),0,1023,1,101);
  Serial.print("x: ");
  Serial.println(x);
  Serial.print("y: ");
  Serial.println(y);
  analogWrite(led,y);
//  delay(1000);

}
