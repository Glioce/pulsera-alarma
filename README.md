# pulsera-alarma
Pulsera con LEDs y un pequeño buzzer

El diseño de referencia es un reloj  
http://www.technoblogy.com/show?1MG3  

El modelo utilizado tiene un LED en el pin 1. De esta forma no debería causar conflictos con otros dispositivos.  
Si el LED está en el pin 0, se debe desconectar para poder utilizar I2C.

Identificar modelos  
https://digistump.com/wiki/digispark/tutorials/modelbi2c  

Limitaciones  
https://digistump.com/wiki/digispark/tutorials/basics  
Pin 3 tiene una resistencia pull-up de 1.5k para USB  
Pin 5 solo puede proporcionar 3V  
Esta es la correspondencia de entradas analógicas con número de pines:  
A1 P2, A2 P4, A3 P3, A0 P5  

Cómo instalar  
https://digistump.com/wiki/digispark/tutorials/connecting  
https://www.luisllamas.es/programar-digispark-con-el-ide-de-arduino/  
Instalación de drivers puede fallar, copiar ruta de archivo y ejecutar como administrador.  

Deshabilitar reset  
http://ihackedathing.blogspot.com/2016/11/digispark-reset-disable.html  
http://thetoivonen.blogspot.com/2015/12/fixing-pin-p5-or-6-on-digispark-clones.html  
Usar avrdude (línea de comandos) o una GUI  
https://blog.zakkemble.net/avrdudess-a-gui-for-avrdude/  
https://github.com/zkemble/AVRDUDESS  

Charlieplexing  
https://en.wikipedia.org/wiki/Charlieplexing

Features and Electrical Characteristics
CPU	8 bit
Number of Programmable I/O pins	6
Operating Voltage	+1.8 V to +5.5V (ATTINY85V) +2.7 V to +5.5V (ATTINY85)(+6.0V being absolute maximum supply voltage)
Maximum DC Current per I/O Pin	40 mA
Maximum DC Current through VCC and GND Pins	200 mA

## Conexiones
LEDs multiplexados en pines 0, 1, 2, 4. No se usa el pin 3 porque tiene resistencia pull-up.  
Buzzer en pin 3. Suena con volumen más alto en pin 3, comparado con pin 5.  
Botón en pin 5. Falta probar

## Mejoras opcionales
Poner interruptor deslizable para apagar fácilmente sin retirar la batería  

Planear el cableado de la cara trasera para que no queden líneas encimadas  

Soldar digispark a la placa grande para resultado más compacto  

Imprimir tapita para cubrir parte trasera y tener espacio para correas  

Buscar buzzer con volumen alto  

Cotizar diseño de la siguiente placa  
