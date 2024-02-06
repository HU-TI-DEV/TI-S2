#include <Arduino.h>
#include <Servo.h>
# define BAUDRATE 9600
# define SERVOPIN 9

// see also code on https://github.com/JeremySCook/Switch/blob/master/detach.ino
// and https://www.makerguides.com/servo-arduino-tutorial/
// put function declarations here:
void servo();

Servo myservo;  // create servo object to control a servo
// max 12 servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(BAUDRATE);
  Serial.println("Start");
  myservo.attach(SERVOPIN);   // attaches the servo on pin 9 to the servo object
}

void loop() {
    servo();
    delay(5000);
}
void servo(){
    myservo.write(60);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the positio
    myservo.write(110);              // tell servo to go to position in variable 'pos'
    delay(500);                       // waits 15ms for the servo to reach the position
    //myservo.detach();
  
  // Sweep from 0 to 180 degrees:
  for (int angle = 0; angle <= 180; angle += 1) {
    myservo.write(angle);
    delay(15);
  }

  // And back from 180 to 0 degrees:
  for (int angle = 180; angle >= 0; angle -= 1) {
    myservo.write(angle);
    delay(15);
  }
  delay(1000);

}