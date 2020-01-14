#include <Servo.h>
char junk;
String inputString="";

int throttle=0;
const int ledPin = 12;
Servo ESC;

void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 pinMode(ledPin, OUTPUT);
 ESC.attach(ledPin);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      throttle=Serial.parseInt();
    }
    Serial.println(throttle);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
    // analogWrite(ledPin, throttle);
     
    inputString = "";
  }
  ESC.writeMicroseconds(throttle); 
  // Serial.println(throttle--);
}// WORKS WITH TERMINAL APP
