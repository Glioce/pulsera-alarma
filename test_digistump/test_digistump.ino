// Pin 0 en Modelo B
// Pin 1 en Modelo A
#define LED_PIN 1

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  delay(1000);
}
