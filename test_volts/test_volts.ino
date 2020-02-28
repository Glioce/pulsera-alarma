// Todos los pines como salida en nivel
// alto para medir los voltajes

void setup() {
  for (byte i=0; i<=5; i++) {
    pinMode(i, INPUT);
    //digitalWrite(i, 0);
  }
}

void loop() {}
