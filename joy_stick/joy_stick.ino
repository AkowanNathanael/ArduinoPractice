int x=A0;
int y=A1;
int z=2;

void setup() {
  // put your setup code here, to run once:
  pinMode(x,INPUT);
  pinMode(y,INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(" x : ");
 Serial.println( map(analogRead(x),0,1023,1,100) );
  Serial.print(" y : ");
 Serial.println(  map(analogRead(y),0,1023,1,100) );
  Serial.print(" z : ");
 Serial.println(analogRead(z));
 
 delay(1000);

}
