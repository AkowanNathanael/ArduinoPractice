#include <WiFi.h>;
#include <HTTPClient.h>;
#include <WiFiClient.h>
//#include <HCSR04.h>
#include <HCSR04.h>
//orignal
const char* ssid = "Daemon";
//Bugs amalina_vs_paula...
const char* password = "amalina_vs_paula...";
HCSR04 hc(23, 15);
//UltraSonicDistanceSensor hc(13, 12);
String state="";
String sub="english";

void setup() {
  // put your setup code here, to run once:0
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to wifi");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }

    Serial.println("\nConnected to the WiFi network");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    
}

void loop() {
  double distance;
  // put your main code here, to run repeatedly:
//  Serial.println(hc.measureDistanceCm());
//Serial.print("distance ");
//  Serial.println(hc.dist());
  if(WiFi.status() == WL_CONNECTED){

    Serial.println("You are fully connected to wifi");
    HTTPClient http;
//192.168.56.47:8383
//192.168.1.2
    http.begin("http:// 192.168.104.47:8383/blind/app/api.php?");
    http.addHeader("Content-Type", "json");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
//       int httpResponseCode = http.POST();
//     int httpResponseCode = http.GET();
      
//       distance=hc.measureDistanceCm();
       distance=hc.dist();
       Serial.print("distance ");
       Serial.println(distance);
      
      if(distance>0 && distance<=5){
        state="play";
     }else if(distance>6 && distance<=10){
      state="pause";
     }else if(distance>11 && distance <=15){
      state="next";
     }else if(distance>16 && distance <=21){
      state="prev";
     }else{
       state = "n/a";
      }

     int httpResponseCode = http.sendRequest("POST", "dist="+String(distance)+String("&") +String("state=") +String(state)+String("&")+String("sub=")+String(sub) );
    
     delay(1000);

    if(httpResponseCode > 0){

       String response = http.getString();
       Serial.println(httpResponseCode);
       Serial.println(response);
       delay(3000);
       
      }else{
        Serial.println("Error on sending POST: ");
        Serial.println(httpResponseCode);
        }

        http.end();
      }// end of wifi status

       else{
        
          Serial.println("Error in WiFi connection");
        }

//      delay(3000);
   
    }
