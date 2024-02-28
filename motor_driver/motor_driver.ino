  int in1=9;
  int in2=10;
  int enA=8;
  int x= A0;
  int myspeed=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(enA,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
 myspeed=map(analogRead(x),0,1023,1,101);
 forward(myspeed);
  
}
void forward(int x){
  analogWrite(in1,x);
  analogWrite(in2,0);
}

void backward(int x){
  analogWrite(in1,0);
  analogWrite(in2,x);
}
