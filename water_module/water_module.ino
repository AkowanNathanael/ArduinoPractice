//water module
int waterpin=A0;
void setup() {
//  pinMode(waterpin, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int val=analogRead(waterpin);
  Serial.println(val);
  // put your main code here, to run repeatedly:

}
