// pines conectados a los LEDs
byte pinLED[] = {0, 1, 2, 4};
//               0  1  2  3
//uint16_t salida = 07770;
//uint16_t salida[12] = {1, 0, 1, 0, 1, 0, 1, 0 , 1, 0, 1, 0};
//                     0  1  2  3  4  5  6  7  8  9 10 11
uint16_t salida[12] = {1, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0};
int t = 3;

void setup() {
  /*
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  //pinMode(3, INPUT);
  pinMode(4, OUTPUT);
  //pinMode(5, INPUT);

  digitalWrite(0, 0);
  digitalWrite(1, 1);
  digitalWrite(2, 0);
  //digitalWrite(3, HIGH);
  digitalWrite(4, 1);
  //digitalWrite(5, HIGH);
  */
}

void loop() {
  //barrido();

  //Grupo 0 ///////////////////////////////////////////
  pinMode(0, OUTPUT);
  digitalWrite(0, 0);
  
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);
  pinMode(4, OUTPUT);
  digitalWrite(1, 1);
  //digitalWrite(2, 0);
  digitalWrite(4, 1);

  delay(t);

  //Grupo 1 //////////////////////////////////////////
  pinMode(1, OUTPUT);
  digitalWrite(1, 0);
  
  pinMode(0, INPUT);
  pinMode(2, OUTPUT);
  pinMode(4, INPUT);
  //digitalWrite(0, 0);
  digitalWrite(2, 1);
  //digitalWrite(4, 0);

  delay(t);

  //Grupo 2 ///////////////////////////////////////
  pinMode(2, OUTPUT);
  digitalWrite(2, 0);
  
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(4, INPUT);
  digitalWrite(0, 1);
  digitalWrite(1, 1);
  //digitalWrite(4, 0);

  delay(t);

  //Grupo 4 ///////////////////////////////////////
  pinMode(4, OUTPUT);
  digitalWrite(4, 0);
  
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  //digitalWrite(0, 0);
  digitalWrite(1, 1);
  digitalWrite(2, 1);
  
  delay(t);
}

void barrido() {
  // usa un array de 12 elementos
  // cada elemento indica el estado de un LED

  /*for (byte i = 0; i <= 3; i ++) {
    pinMode(pinLED[i], OUTPUT); //
    digitalWrite(pinLED[i], 0); //
    }*/

  byte k = 0; //posición en el array

  for (byte i = 0; i <= 3; i ++) {
    pinMode(pinLED[i], OUTPUT); //salida
    digitalWrite(pinLED[i], 0); //en nivel bajo (GND)

    for (byte j = 0; j <= 3; j ++) {
      if (i != j) { //no puede ser el mismo pin
        if (salida[k] == 1) {
          pinMode(pinLED[j], OUTPUT); //salida
          digitalWrite(pinLED[j], 1); //encendido
        }
        else {
          digitalWrite(pinLED[j], 0); //apagar
          pinMode(pinLED[j], INPUT); //entrada
        }

        k ++; //incrementar posición
        delay(1);
      }
    }
  }
}
