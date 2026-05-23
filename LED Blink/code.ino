void setup() {
  pinMode(2, OUTPUT);
}

void loop() {

  digitalWrite(2, HIGH); // LED ON
  delay(500);

  digitalWrite(2, LOW);  // LED OFF
  delay(500);
}
