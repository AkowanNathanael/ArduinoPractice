
#include "BluetoothSerial.h"

BluetoothSerial SerialBT;
String  feed="";
char incoming;
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
 while(SerialBT.available()){
  incoming=SerialBT.read();
  feed+=incoming;
  if (feed="1"){
    feed="";
  }else if(feed=="on"){
    digitalWrite(13,1);
  }else if(feed=="of"){
    digitalWrite(13,0);
  }else {
    continue;
  }
  Serial.println(feed);
 }
Serial.println(feed);
}
