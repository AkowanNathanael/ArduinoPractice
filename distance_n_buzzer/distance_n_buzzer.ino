
#include <HCSR04.h>
HCSR04 hc(8,9);
void setup() {
  // put your setup code here, to run once:

}

void loop() {
   int value=hc.dist();
  if(value >=15){
    Serial.println(value);
    tone();
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH);
  }else{
    Serial.println(value);
     digitalWrite(LED_BUILTIN, LOW); 
     delay(500);   
    }
  // put your main code here, to run repeatedly:

}
