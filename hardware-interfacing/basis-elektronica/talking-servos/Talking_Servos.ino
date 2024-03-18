#include <Servo.h>

Servo myservo0;  // create servo object to control a servo
Servo myservo1;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    	  // variable to read the value from the analog pin

int buttonPin = 7;
int pwmPinServo0 = 8;
int pwmPinServo1 = 9;

void setup() {
  pinMode(buttonPin,INPUT);
  myservo0.attach(pwmPinServo0);  // attaches the servo on pin 9 to the servo object
  myservo1.attach(pwmPinServo1);  // attaches the servo on pin 8 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo0.write(val);                 // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
  if(digitalRead(buttonPin))
  {
    myservo1.write(180);
  }
  else
  {
    myservo1.write(0);
  }
}
