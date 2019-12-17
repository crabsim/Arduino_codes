int pin1=5;
int pin2=6;
int tpin=3;
int epin=7;
int pin3=8;
int pin4=9;
long duration,dist;
void setup() {
  // put your setup code here, to run once:
pinMode(tpin,OUTPUT);
pinMode(epin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(tpin,LOW);
delayMicroseconds(2);
digitalWrite(tpin,HIGH);
delayMicroseconds(10);
digitalWrite(tpin,LOW);
duration=pulseIn(epin,HIGH);
dist=duration*(0.034/2);
Serial.println(dist);
delay(1000);
if(dist>10)
{
  forward();
}
if(dist<10)
{
  backward;
}
}
void forward()
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
}
void backward()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
}
