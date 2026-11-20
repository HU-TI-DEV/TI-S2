void setup() {
  Serial.begin(115200);
  Serial.setTimeout(400);
}

void loop() {
  Serial.println("This is a test. 0123456789 ");
  String msg = Serial.readString();
  Serial.print("MSGLEN ");
  Serial.println(msg.length());
  delay(1000);
}
