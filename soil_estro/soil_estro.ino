//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
int hygro=A0;
int relay=8;
int water=A1;
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  pinMode(relay,OUTPUT);
  // Print a message to the LCD.
  Serial.begin(9600);
  lcd.backlight();
//  lcd.setCursor(3,0);
//  lcd.print("Hello, world!");
//  lcd.setCursor(2,1);
//  lcd.print("Ywrobot Arduino!");
//   lcd.setCursor(0,2);
//  lcd.print("Arduino LCM IIC 2004");
//   lcd.setCursor(2,3);
//  lcd.print("Power By Ec-yuan!");
}


void loop()
{
  Serial.println(analogRead(hygro));
  Serial.println(analogRead(water));
  int level1=analogRead(hygro);
  int level2=analogRead(water);
  if (level1 <= 500){
   lcd.setCursor(0,0);
//   String(level1)
   lcd.print("moist : (high)" );
   digitalWrite(relay,LOW);
  }else{
    lcd.setCursor(0,0);
//     + String(level1)
  lcd.print("moist : (low) ");
  digitalWrite(relay,HIGH);
  }
//  if (water>830){
//    
//  }else{
//    
//  }
// 
  lcd.setCursor(0,1);
  lcd.print("water level " + String(level2));
  delay(1000);
  
}
