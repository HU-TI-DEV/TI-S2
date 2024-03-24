// PWM.ino - Pulse Width Modulation example (fan control)
// "Fading in and out" of maximum fan speed.
int delay_ms = 300;  // delay for the main loop
int fan_pin = 6;     // the PWM pin we use (make sure the pin supports PWM if you change this!)
int fan_speed = 0;   // current speed of the fan
int fan_delta = 5;   // amount to change the speed (pos/neg)

void built_in_self_test() {
  // flash built-in LED three times
  pinMode(LED_BUILTIN, OUTPUT);
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
}

void setup() {
  built_in_self_test();
  pinMode(fan_pin, OUTPUT);  // declare PWM pin to be an output
}

void loop() {
  // set the speed of fan by generating a PWM signal
  analogWrite(fan_pin, fan_speed);
  // change the speed for next iteration
  fan_speed = fan_speed + fan_delta;
  // make sure fan_speed does not get lower than 0 or higher than 255
  if (fan_speed < 0) {
    fan_speed = 0;
  } else if (fan_speed > 255) {
    fan_speed = 255;
  }
  // reverse the direction of the fan_delta at the ends of the 'fade'
  if (fan_speed <= 0 || fan_speed >= 255) {
    fan_delta = -fan_delta;
  }
  // wait for 300 milliseconds to see the fade effect
  delay(300);
}
