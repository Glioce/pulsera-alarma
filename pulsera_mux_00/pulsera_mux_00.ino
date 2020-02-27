// Pin 0 en Modelo B
// Pin 1 en Modelo A
#define LED_PIN 1

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(400);
  digitalWrite(LED_PIN, LOW);
  delay(50);
}

void barrido(uint16_t a) {
  // la entrada en un valor de 16 bits
  // solo se utilizan 12 bits
  // es preferible escribir el valor en formato octal
  // cada dígito octal representa un grupo de 3 LEDs
}
