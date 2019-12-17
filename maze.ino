int m1=2;
int m2=3;
int m3=4;
int m4=5; 
int pin1=8;
int pin2=9;
int pin3=11;
void setup() {
  // put your setup code here, to run once:
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
pinMode(pin1,INPUT);
pinMode(pin2,INPUT);
pinMode(pin3,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(pin1));
if(pin1==LOW && pin2==LOW && pin3==LOW)
{
 st();
}
if(digitalRead(pin1)==LOW && digitalRead(pin2)==HIGH && digitalRead(pin3)==HIGH)
{
 left();
}
if(digitalRead(pin1)==HIGH && digitalRead(pin2)==LOW && digitalRead(pin3)==LOW)
{
 right();
}
if(digitalRead(pin1)==LOW && digitalRead(pin2)==HIGH && digitalRead(pin3)==LOW)
{
forward();
}
if(digitalRead(pin1)==LOW && digitalRead(pin2)==LOW && digitalRead(pin3)==HIGH)
{
left();
}
if(digitalRead(pin1)==HIGH && digitalRead(pin2)==HIGH && digitalRead(pin3)==LOW)
{
 right();
}
if(digitalRead(pin1)==HIGH && digitalRead(pin2)==HIGH && digitalRead(pin3)==HIGH)
{
 forward();
}
  
}
void forward()
{
digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
}
void backward()
{
 digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
}
void left()
{
digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
}
void right()
{
digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
}
void st()
{
digitalWrite(m1,LOW);
digitalWrite(m2,LOW);
digitalWrite(m3,LOW);
digitalWrite(m4,LOW);
}
