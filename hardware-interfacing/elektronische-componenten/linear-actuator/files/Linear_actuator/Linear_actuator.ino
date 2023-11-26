//assign relay INx pin to arduino pin
const int forwards = 7;
const int backwards = 6;

void setup() {
  //set pin as output
  pinMode(forwards, OUTPUT);
  pinMode(backwards, OUTPUT);
}

void loop() {
  //Activate the relay one direction
  digitalWrite(forwards, LOW);
  digitalWrite(backwards, HIGH);
  delay(2000); // wait 2 seconds
  //Deactivate both relays to brake the motor
  digitalWrite(forwards, HIGH);
  digitalWrite(backwards, HIGH);
  delay(20000);// wait 20 seconds
  //Activate the relay the other direction
  digitalWrite(forwards, HIGH);
  digitalWrite(backwards, LOW);
  delay(2000);// wait 2 seconds
  //Deactivate both relays to brake the motor
  digitalWrite(forwards, HIGH);
  digitalWrite(backwards, HIGH);
  delay(20000);// wait 20 seconds
}
