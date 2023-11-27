//L298N driver motor B connected, setup Arduino Pins
const int IN3 = 5;
const int IN4 = 4;
const int ENB = 3;

void setup() {
  //set pin as output
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  //control speed
  analogWrite(ENB, 125); 
  //control direction
  //one way 
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(5000);// wait 5 seconds
  //other way
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(5000);// wait 5 seconds
  //break the motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(50000);// wait 50 seconds
}
