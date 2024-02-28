#include <WiFi.h>
#include <HTTPClient.h>
#include <WiFiClient.h>
//#include <HCSR04.h>
#include <HCSR04.h>
//orignal
const char* ssid = "BotBugs";
//Bugs amalina_vs_paula...
const char* password = "amalina_vs_paula...";
HCSR04 hc(23, 22);
//UltraSonicDistanceSensor hc(23, 15);
String state = "";
String sub = "english";
//int button_eng = 22;
//int button_math = 4;
//int button_science = 18;
const int pin=34;

void setup() {
  // put your setup code here, to run once:0
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to wifi");

  while (WiFi.status() != WL_CONNECTED) {
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
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("You are fully connected to wifi");
    HTTPClient http;
    //192.168.56.47:8383
    //192.168.142.47  
    http.begin("http://192.168.142.47:8383/blindo/app/api.php?");
    http.addHeader("Content-Type", "json");
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    //       int httpResponseCode = http.POST();
    //     int httpResponseCode = http.GET();
//    distance=hc.measureDistanceCm();
    distance = hc.dist();
    Serial.print("distance : ");
    Serial.println(distance);
    int val=analogRead(pin);
    Serial.print("potentiometer : ");
    Serial.println(val);
//    get val and determine suject
    if(val>0 && val<1800){
       sub="english";
    }else if(val>1800 && val <3500){
       sub="science";
    }else if(val>3500){
       sub="maths";
    }
//get  distance and determine state of audio i.e play pause,next,prev
    if (distance > 0 && distance <= 5) {
      state = "play";
    } else if (distance > 6 && distance <= 10) {
      state = "pause";
    } else if (distance > 11 && distance <= 15) {
      state = "next";
    } else if (distance > 16 && distance <= 21) {
      state = "prev";
    } else {
      state = "n/a";
    }

    int httpResponseCode = http.sendRequest("POST", "dist=" + String(distance) + String("&") + String("state=") + String(state)+String("&") + String("sub=") + String(sub));

    delay(1500);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
      delay(1500);
    } else {
      Serial.println("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  }// end of wifi status
  else {
    Serial.println("Error in WiFi connection");
  }
//        delay(2000);
}
