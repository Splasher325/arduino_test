#include <Servo.h>
Servo ESC;
int potpin=6;
int input;
int swpin=3;

void setup() {
  Serial.begin(9600);
  ESC.attach(6);
}

void loop() {
  // Read analog input
  // Serial.println(analogRead(3)); // 0 if pushed
  if(analogRead(swpin)==0) {
    input = analogRead(potpin);
    // Serial.println("pushed");
    // Map for Servo signal
    input=map(input, 0, 1023, 0, 179);
  
    // Send digital signal out D6
  
    ESC.write(input);
  }
  // Digital output on Serial Monitor
  // Serial.println(digitalRead(12));
  
  // Delay 20ms for 50Hz PWM signal
  delay(20);
}
