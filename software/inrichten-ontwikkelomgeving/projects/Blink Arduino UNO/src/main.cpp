#include <Arduino.h>
# define BAUDRATE 9600
# define GREENLED 13

// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  // int result = myFunction(2, 3);
  Serial.begin(BAUDRATE);
  pinMode(GREENLED, OUTPUT);
  Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(GREENLED,LOW);
  Serial.println("The green led is off");
  delay(1000);
  digitalWrite(GREENLED, HIGH);
  Serial.println("The green led is on");
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}