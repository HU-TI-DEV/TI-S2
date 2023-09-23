int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
// anynumber < 256, decimal 123 is binary 01111011
int anyNumber = 123; 

void setup() {
  //set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  // latchPin low, LEDs do not turn on while sending bits
  digitalWrite(latchPin, LOW);
  // shift out the bits
  shiftOut(dataPin, clockPin, MSBFIRST, anyNumber);
  //take the latch pin high, LEDs turn on
  digitalWrite(latchPin, HIGH);
}
