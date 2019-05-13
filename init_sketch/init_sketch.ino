#include <Servo.h>

Servo ESC;
int potpin=6;
int input;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ESC.attach(6);

  
  /*
  Serial.begin(9600);
  Serial.print(0);
  axis_pin = A0;
  sig_pin = 6;
  pinMode(sig_pin, OUTPUT);
  */
}

void loop() {
  // put your main code here, to run repeatedly:

  input = analogRead(potpin);
  input=map(input, 0, 1023, 0, 179);
  ESC.write(input);
  Serial.println(digitalRead(12));
  delay(1000);
  
  /*
  input = analogRead(axis_pin);
  Serial.print(input);
  output = map(input, 0, 1023, 0, 255);
  digitalWrite(sig_pin, output);
  */


  //delay(20);
}
