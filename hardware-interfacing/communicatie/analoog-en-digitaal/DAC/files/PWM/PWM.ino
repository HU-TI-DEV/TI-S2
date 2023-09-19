int fan = 6;           // the PWM pin
int speed = 0;        // speed of the fan
int fadeSpeed = 5;    // how many points to fade the speed by

void setup() {
  pinMode(fan, OUTPUT); // declare pwm pin to be an output:
}

void loop() {
  analogWrite(fan, speed); // set the speed of fan

  // change the speed for next time through the loop:
  speed = speed + fadeSpeed;

  // reverse the direction of the fading at the ends of the fade:
  if (speed <= 0 || speed >= 255) {
    fadeSpeed = -fadeSpeed;
  }  
  delay(300);  // wait for 300 milliseconds to see the fade effect
}
