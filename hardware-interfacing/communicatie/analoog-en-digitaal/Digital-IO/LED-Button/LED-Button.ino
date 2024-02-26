// LED-Button.ino - Digital Input/Output example - 2024-02-15-hp
// Tested on Arduino Uno
// [+5V]---[=1kOhm=]---[LED]---[D2]
// [GND]---[Button]---[D3]

const int delaytime_ms = 500;  // delay 1000ms = 1s, 500ms = 0.5s
const int pinLED = 2;          // Pin 2 - Digital Output
const int pinButton = 3;       // Pin 3 - Digital Input

int stateLED = 1;  // start state: LED off

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, stateLED);  // LED off (initial)
}

void loop() {
  if (digitalRead(pinButton) == LOW) {
    stateLED = 1 - stateLED;         // reverse LED status
    digitalWrite(pinLED, stateLED);  // LED on or off (stateLED==0 -> ON, stateLED==1 -> OFF)
    delay(delaytime_ms);
  }
}

// EOF
