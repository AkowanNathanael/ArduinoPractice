int relay=2;
int led=13;
int r1=8;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led, OUTPUT);
pinMode(relay, OUTPUT);
pinMode(r1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led, HIGH);
   digitalWrite(relay, HIGH);
    digitalWrite(r1, HIGH);
  delay(2000);
  digitalWrite(led, LOW);
   digitalWrite(relay, LOW);
    digitalWrite(r1, LOW);
  delay(2000);
}
