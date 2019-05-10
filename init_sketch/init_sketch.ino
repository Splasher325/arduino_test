int output;
int input;
int axis_pin;
int sig_pin;

void setup() {
  // put your setup code here, to run once:
  axis_pin= A0;
  sig_pin=6;
}

void loop() {
  // put your main code here, to run repeatedly:
  input = analogRead(axis_pin);
  output = map(input, 0, 1023, 0, 255);\
  analogWrite(sig_pin,output)
  
  
  
  delay(20);
}
