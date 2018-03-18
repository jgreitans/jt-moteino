#define LED 9

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  delay(1000);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
}
