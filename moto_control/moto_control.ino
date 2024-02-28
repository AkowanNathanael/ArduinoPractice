//  #include <Servo.h>
//  Servo myservo;
//  int pos;
  int in1=8;
  int in2=9;
  int in3=10;
  int in4=11;
//  int joyx=A0;
//  int joyy=A1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
//  pinMode(13,OUTPUT);
//  myservo.attach(7); 

}
void loop() {
  delay(2000);
  forw();
  delay(1000);
  stopnow();
  delay(3000);
  back();
  delay(2000);
  fright();
  delay(2000);
    fleft();
  delay(2000);
    bleft();
  delay(2000);
   bright();
  delay(2000);
//for (pos = 0; pos <= 180; pos++) { 
//    // in steps of 1 degree
//    myservo.write(pos);              
//    delay(10);                      
//  }

//for (pos = 180; pos >= 0; pos--) { 
//    // in steps of 1 degree
//    myservo.write(pos);              
//    delay(10);                      
//  }
//for (pos = 0; pos <= 360; pos += 1) { // goes from 0 degrees to 180 degrees
//    // in steps of 1 degree
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(10);                       // waits 15ms for the servo to reach the position
//  }
//  for (pos = 360; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
//    myservo.write(pos);              // tell servo to go to position in variable 'pos'
//    delay(10);                       // waits 15ms for the servo to reach the position
//  }


//int x=map(analogRead(A0),0,1023,0,99);
//int y=map(analogRead(A1),0,1023,0,99);
//Serial.print("X: ");
//Serial.println(x);
//Serial.print("Y: ");
//Serial.println(y);
//delay(500);

}
