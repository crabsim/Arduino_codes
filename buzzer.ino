void setup() {
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(7,HIGH);
  digitalWrite(13,HIGH);
  
  Serial.println("\nFire Detected!!! activating cooler and alarm !!");  

  delay(3000);
  digitalWrite(7,LOW);
  digitalWrite(13,LOW);  int i;
  for(i=0;i<8;i++)
  {
     Serial.println("Ideal Task");   delay(500); 
    } 
  delay(1/0);

}
