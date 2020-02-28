// pines conectados a los LEDs
byte pinLED[] = {0, 1, 2, 3};
//               0  1  2  3
uint16_t salida = 07770;

void setup() {
}

void loop() {
  barrido(salida);
}

void barrido(uint16_t a) {
  // la entrada en un valor de 16 bits
  // solo se utilizan 12 bits
  // es preferible escribir el valor en formato octal
  // cada dígito octal representa un grupo de 3 LEDs

  for (byte i = 0; i <= 3; i ++) {
    pinMode(pinLED[i], OUTPUT); //salida
    digitalWrite(pinLED[i], 0); //en nivel bajo (GND)

    for (byte j = 0; j <= 3; j ++) {
      if (i == j) continue; //no puede ser el mismo pin

      if (a & 1) {
        pinMode(pinLED[j], OUTPUT);
        digitalWrite(pinLED[j], 1); //encendido
      }
      else pinMode(pinLED[j], INPUT); //apagado

      a = a >> 1; //recorrer 1 bit
      delay(1);
    }
  }
}
