// PWM.ino - Pulse Width Modulation example (fan control)
int delay_ms = 300;   // delay for th emain loop
int fan_pin = 6;      // the PWM pin we use (make sure the pin supports PWM if you change this!)
int fan_speed = 0;    // current speed of the fan
int fan_delta = 5;    // amount to change the speed (pos/neg)

void setup() {
  pinMode(fan_pin, OUTPUT); // declare PWM pin to be an output
}

void loop() {
  analogWrite(fan_pin, fan_speed); // set the speed of fan by generating a PWM signal

  // change the speed for next iteration
  fan_speed = fan_speed + fan_delta;

  // reverse the direction of the fading at the ends of the fade:
  if (fan_speed <= 0 || fan_speed >= 255) {
    fan_delta = -fan_delta;
    // We need to make sure speed does not wrap
    if (speed < 0) {
      fan_speed = 0;
    } else if (speed > 255) {
      fan_speed = 255;
    }
  }  
  delay(300);  // wait for 300 milliseconds to see the fade effect
}
