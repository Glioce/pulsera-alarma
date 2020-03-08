/****************************************************************
  W-ALERT

  Es un dispositivo que se usa como pulsera.
  Presiona el botón para activar o descarivar la alarma.
  Cuando la alarma está activada, se encienden luces y un buzzer.
*****************************************************************/

// Definición de pines
#define pinBoton 5 //botón para activar alarma
#define pinBuzzer 3 //zumbador
byte pinLED[] = {0, 1, 2, 4}; //pines conectados a los LEDs
//pos. en array: 0  1  2  3

// Variables globales
uint16_t salida = 05252; //patrón que se muestra en los LEDs
byte boton = 1; //estado actual del botón
byte botonPrev = 1; //estado previo del botón
byte alarma = 0; //inicia con alarma desactivada
byte buzzer = 1; //estado del buzzer
unsigned long t = 0; //tiempo actual
unsigned long tBoton = 0; //momento de leer el estado del botón
unsigned long tAnim = 0; //momento de cambiar el patron de animación
unsigned long tBuzzer = 0; //momento de cambiar el estado del buzzer
int contAnim = 0; //contador para la animación

void setup() {
  // Botón pulsador
  // Cuando no está pulsado, se lee el valor 1.
  // Cuando se presiona, cambia a 0 (nivel bajo).
  pinMode(pinBoton, INPUT_PULLUP);

  // Buzzer
  // Está conectado directamente al polo positivo de la
  // fuente de alimentación. Tiene lógica invertida:
  // Cuando la salida es 1, el buzzer está apagado
  // Cuando la salida es 0, el buzzer está encendido
  pinMode(pinBuzzer, OUTPUT);
  digitalWrite(pinBuzzer, 1); //apagado
} 

void loop() {
  t = millis(); //leer tiempo actual

  if (t >= tBoton) {
    boton = digitalRead(pinBoton); //leer estado del botón
    if (boton == 0 and botonPrev == 1) {//si se acaba de presionar
      alarma ^= 1; //activar o desactivar la alarma

      if (alarma) {//si se acaba de activar la alarma
        contAnim = 0; //reiniciar contador
        tAnim = t; //actualizar tiempo
        buzzer = 1; //preparar buzzer
        tBuzzer = t; //actualizar tiempo
      }
    }
    botonPrev = boton; //actualizar estado previo
    tBoton += 20; //esperar antes de volver a leer el botón
  }

  if (alarma) {// si la larma está activada
    if (t >= tAnim) {//si es momento de cambiar el patrón
      switch (contAnim) {//asignar uno de los patrones
        case 0: salida = 07777; tAnim += 300; break;
        case 1: salida = 01004; tAnim += 300; break;
        case 2: salida = 05252; tAnim += 300; break;
        case 3: salida = 02525; tAnim += 300; break;
      }
      //incrementar contador, si es mayor a 3, regresa a 0
      contAnim = ++contAnim % 4;
    }

    barrido(salida); //mostrar patrón
    digitalWrite(pinBuzzer, 0); //encender buzzer
  }
  else { // si la alarma está apagada
    barrido(0); //apagar LEDs
    digitalWrite(pinBuzzer, 1); //apagar buzzer
  }
}

void barrido(uint16_t a) {
  // la entrada en un valor de 16 bits
  // solo se utilizan 12 bits
  // es recomendable escribir el valor en formato octal
  // cada dígito octal representa un grupo de 3 LEDs

  for (byte i = 0; i <= 3; i ++) {
    pinMode(pinLED[i], OUTPUT); //salida
    digitalWrite(pinLED[i], 0); //en nivel bajo (GND)

    for (byte j = 0; j <= 3; j ++) {
      if (i == j) continue; //no puede ser el mismo pin

      if ((a & 1) == 1) {
        pinMode(pinLED[j], OUTPUT);
        digitalWrite(pinLED[j], 1); //encendido
      }
      else {
        digitalWrite(pinLED[j], 0);
        pinMode(pinLED[j], INPUT); //apagado
      }
      a = a >> 1; //recorrer 1 bit
    }
    delay(1);
  }
}
