#include <Wire.h>

#include <Adafruit_Sensor.h>

#include <Adafruit_ADXL345_U.h>

int pin1=3;
int pin2=5;
int pin3=6;
int pin4=9;

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);//creating an object adhering
float x0,y0,z0;
void setup(void)
{
  Serial.begin(9600);

  accel.begin();//initialising sensor
  
  sensors_event_t event;//creating event to get accn. in 3 dirn.//syntax
  accel.getEvent(&event);//calling values of the event//syntax

  x0=event.acceleration.x;//to get x component of accn.
  y0=event.acceleration.y;
  z0=event.acceleration.z;

  Serial.println(x0);
  Serial.println(y0);
  Serial.println(z0);
  Serial.println("");
   
}

void loop(void)
{
  //get a new sensor event
  sensors_event_t event;
  accel.getEvent(&event);

  float x=event.acceleration.x;
  //getting x y and z dirn.//when we tilt it it will get accn.
  float y=event.acceleration.y;
  float z=event.acceleration.z;

  Serial.println("x:");Serial.println(x);Serial.println(" ");
  Serial.println("y:");Serial.println(y);Serial.println(" ");
  Serial.println("z:");Serial.println(z);Serial.println(" ");Serial.println("m/s^2");//metre per second square
  delay(500);

//setting the conditions for forwrd reverse right left
if(x>x0+3)
{
  Serial.println("left");
  dleft();
}
else if(x<x0-3)
{
  Serial.println("right");
  dright();
}
else if(y>y0+3)
{
  Serial.println("reverse");
  dreverse();
}
else if(y0<y0-3)
{
  Serial.println("forward");
  dforward();
}
else if(x0<x0+3 && x>x0-3 && y0<y0+3 && y0>y0-3)
{
  Serial.println("brake");
  dstate();
}
}
void dright()
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
}
void dforward()
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
}  
void dreverse()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,HIGH);
  digitalWrite(pin4,LOW);
}
void dleft()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,HIGH);
}
void dstate()
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin3,LOW);
  digitalWrite(pin4,LOW);
}
    

 
