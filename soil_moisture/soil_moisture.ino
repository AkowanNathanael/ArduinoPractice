//water module
int soil_pin=A0;
int soil_pin2=7;
void setup() {
//  pinMode(waterpin, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
//  int val=analogRead(soil_pin);
  int val=digitalRead(soil_pin2);
  Serial.println(val);
  // put your main code here, to run repeatedly:

}
