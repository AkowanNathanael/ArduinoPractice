char mydata='0';
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Arduino Serial");
}

// the loop function runs over and over again forever
void loop() {
  while (Serial.available()){
    mydata=Serial.read();
    
  }

  if (mydata=='1'){
    digitalWrite(LED_BUILTIN, HIGH); 
  }else if (mydata=='0'){
    digitalWrite(LED_BUILTIN, LOW);
  }
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
}
