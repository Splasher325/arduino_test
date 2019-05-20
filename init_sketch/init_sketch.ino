#include <Servo.h>
Servo ESC;
int potpin=6;
int input;
int swpin=3;

void setup() {
  Serial.begin(9600);
  ESC.attach(6);
  ESC.writeMicroseconds(1000);
}

void loop() {
  // Read analog input
  // Serial.println(analogRead(3)); // 0 if pushed
  if(analogRead(swpin)==0) { //Safety button
    input = analogRead(potpin);
    // Serial.println("pushed");
    // Map for Servo signal
    input=map(input, 0, 1023, 1000, 2000); //Synthesizing the pwm siganl with SERVO library
  
    // Send digital signal out D6
  
    ESC.writeMicroseconds(input); //Sending synthesized signal
  }
  // Digital output on Serial Monitor
  // Serial.println(digitalRead(12));
  
  // Delay 20ms for 50Hz PWM signal
  // delay(20);
}
