#include <IRremote.h>0

//define sensor pin
const int ir=8;
IRrecv irrecv(ir);
decode_results results;

void setup(){
  Serial.begin(9600);
//  enable th ir receiver
irrecv.enableIRIn();
}


void loop(){
  if(irrecv.decode(&results)){
//    print code on hex or dec
    Serial.println(results.value,HEX);
//    disable Ir  
      irrecv.resume();
  }
   
}
