#include <HCSR04.h>;
int buz=8;
int btn=5;
HCSR04 hc(7,6);
void setup() {
  // put your setup code here, to run once:
  pinMode(buz,OUTPUT);
   pinMode(btn,INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pin_mode=digitalRead(btn);
  if(pin_mode){
    Serial.println("on");
//    digitalWrite(buz,HIGH);
//      buz=8;
//     tone(buz,900);
//     delay(1000);
  }
  else {
    Serial.println("off");
//    buz=0;
//     tone(buz,1);
// digitalWrite(buz,LOW);
  }
  delay(500);
//  Serial.println("buz");
//  Serial.println(hc.dist());
//  Serial.println("buz");
//   delay(300);
//   double dis=hc.dist();
//   if(dis>10){
//     tone(buz,100);
//     delay(1000);
//   }else{
//     tone(buz,900);
//     delay(1000);
//   }
//  tone(buz,900);
//  delay(1000);
//  for(int i=0;i<1000;i++){
//    Serial.println("i "+ String(i));
//    tone(buz,i);
//  delay(100);
//  }
  
  
} 
