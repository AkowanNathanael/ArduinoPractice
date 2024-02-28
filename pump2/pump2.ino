
// the setup function runs once when you press reset or power the board
int water_level;
int soil_moist;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(A0,INPUT);
   pinMode(A5,INPUT);
}

// the loop function runs over and over again forever
void loop() {
  water_level=analogRead(A0);
  soil_moist=analogRead(A5);
  Serial.print("water : ");
  Serial.println(water_level);
  Serial.print("soil : ");
  Serial.println(soil_moist);
   delay(1000);
  if(water_level<400){
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(2000);
  }else {
  digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000); 
  }
                         // wait for a second
                        // wait for a second
}
