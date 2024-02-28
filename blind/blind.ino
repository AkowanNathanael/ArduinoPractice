#include <WiFi.h>;
#include <HTTPClient.h>;
#include <WiFiClient.h>
#include <HCSR04.h>

const char* ssid = "kim";
//Bugs amalina_vs_paula...
const char* password = "1234567890";
HCSR04 hc(15,2);


void setup() {
  // put your setup code here, to run once:
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
  String state;
  // put your main code here, to run repeatedly:
  Serial.println(hc.dist());
  if(WiFi.status() == WL_CONNECTED){

    Serial.println("You are fully connected to wifi");
    HTTPClient http;
    tone(4,0);

//   192.168.56.47:8383
    http.begin("http://192.168.43.224:8383/api/index.php?");
    http.addHeader("Content-Type", "json");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
   
    delay(2000);
    tone(4,600);
    delay(1300);

//     int httpResponseCode = http.POT("POSTING from ESP32");
//       int httpResponseCode = http.POST();
//     int httpResponseCode = http.GET();
      
       distance=hc.dist();
       state="";
      if(distance>1 || distance<=9){
       state="next";
     }else if(distance>10 || distance<=15){
       state="prev";
     }else if(distance>15 || distance <=20){
       state="pause";
     }else  if(distance>20 || distance <=30){
       state="play";
     }
     int httpResponseCode = http.sendRequest("POST", "dist="+String(distance)+String("&") +String("state=") +String(state) );
    
     delay(1000);


    if(httpResponseCode > 0){

       String response = http.getString();

       Serial.println(httpResponseCode);
       Serial.println(response);
       
      }else{
        Serial.println("Error on sending POST: ");
        Serial.println(httpResponseCode);
        }

        http.end();
      }// end of wifi status

       else{
        
          Serial.println("Error in WiFi connection");
        }

      delay(4000);


   
    }
