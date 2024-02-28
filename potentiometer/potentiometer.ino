const int pin=34;
void setup() {
  // put your setup code here, to run once:
//pinMode(23, INPUT);
Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
// analogRead(22);
String state;
 Serial.println(analogRead(pin));
 int val=analogRead(pin);
 if(val>0 && val<1800){
  state="eng";
 }else if(val>1800 && val <3500){
  state="sci";
 }else if(val>3500){
  state="math";
 }
 Serial.println( "state  : " + state);
 delay(500);
}
