#include <Arduino.h>
# define BAUDRATE 9600
# define GREENLED 13

// put function declarations here:
void showLED (int pin, int delayPeriod, bool ledStatus);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  pinMode(GREENLED, OUTPUT);
  Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  showLED (GREENLED, 1000, HIGH);
  showLED (GREENLED, 1000, LOW);
}

// put function definitions here:
void showLED (int pin, int delayPeriod, bool ledStatus) {
  if (ledStatus){
    Serial.println("The green led is on");
    digitalWrite(pin, HIGH);
  }
  else{
    Serial.println("The green led is off");
    digitalWrite(pin, LOW);
  }
  delay(delayPeriod);
}