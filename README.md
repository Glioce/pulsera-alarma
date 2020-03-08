# W-ALERT (pulsera-alarma)
Es un dispositivo que se usa como pulsera.
Presiona el botón para activar o descarivar la alarma.
Cuando la alarma está activada, se encienden luces y un buzzer.

Diseño en TinkerCAD  
https://www.tinkercad.com/things/agNZqK1bCSm

El diseño de referencia es un reloj  
http://www.technoblogy.com/show?1MG3  

## Hardware del prototipo
El prototipo utiliza como controlador un clon de la tarjeta de desarrollo Digispark modelo A. Esta tarjeta se puede programar con el IDE de Arduino. Sobre la tarjeta está montado un microcontrolador ATTiny 85, con un bootloader que permite reprogramarlo a través del puerto USB sin necesidad de un dispositivo externo.  

Características del ATTiny85  
CPU	8 bit  
Number of Programmable I/O pins	6  
Operating Voltage	+1.8 V to +5.5V (ATTINY85V) +2.7 V to +5.5V (ATTINY85)(+6.0V being absolute maximum supply voltage)  
Maximum DC Current per I/O Pin	40 mA  
Maximum DC Current through VCC and GND Pins	200 mA  

Identificar modelos  
https://digistump.com/wiki/digispark/tutorials/modelbi2c  

El modelo utilizado tiene un LED en el pin 1. De esta forma no debería causar conflictos si se utiliza I2C.  
En otros modelos el LED está en el pin 0, se debe desconectar para poder utilizar I2C.

Limitaciones  
https://digistump.com/wiki/digispark/tutorials/basics  
Pin 3 tiene una resistencia pull-up de 1.5k para USB, se debe tener en consideración  
Pin 5 es un GPIO "débil", solo puede proporcionar 3V  
Esta es la correspondencia de entradas analógicas con número de pines:  
A1 P2  
A2 P4  
A3 P3  
A0 P5  

Cómo instalar tarjeta en IDE de Arduino y controladores para comunicación USB  
https://digistump.com/wiki/digispark/tutorials/connecting  
https://www.luisllamas.es/programar-digispark-con-el-ide-de-arduino/  
La instalación de los drivers USB puede fallar. Copiar ruta de archivo y ejecutar como administrador.  

Deshabilitar reset  
Algunas tarjetas tenían habilitado el pin de reset. De esa forma el pin no se puede utilizar como GPIO.  
http://ihackedathing.blogspot.com/2016/11/digispark-reset-disable.html  
http://thetoivonen.blogspot.com/2015/12/fixing-pin-p5-or-6-on-digispark-clones.html  
Usar avrdude (línea de comandos) o una GUI  
https://blog.zakkemble.net/avrdudess-a-gui-for-avrdude/  
https://github.com/zkemble/AVRDUDESS  

Charlieplexing  
Se controlan 12 LEDs con 4 pines del microcontrolador usando multiplexación. La técnica utilizada es charlieplexing.  
https://en.wikipedia.org/wiki/Charlieplexing

## Conexiones
LEDs multiplexados en pines 0, 1, 2, 4. No se usa el pin 3 porque tiene resistencia pull-up.  
Buzzer en pin 3. Suena con volumen más alto en pin 3, comparado con pin 5.  
Botón en pin 5. Se activa resistencia pull-up interna. Cuando se presiona el botón conecta a GND. No se usó este pin para un actuador porque es un GPIO "débil" y el botón no se conectó en el pin 3 porque al conectar a GND a veces se reiniciaba.  

## Mejoras opcionales
Planear el cableado de la cara trasera para que no queden líneas encimadas  

Soldar digispark a la placa grande para resultado más compacto  

Imprimir tapita para cubrir parte trasera y tener espacio para correas  

Buscar buzzer con volumen alto  

Cotizar diseño de la siguiente placa  

Programar sleep mode para ahorrar energía  
https://wiki.liutyi.info/display/ARDUINO/Low+power+projects+digispark+ATtiny85+modification  
https://forum.arduino.cc/index.php?topic=557534.0  
https://digistump.com/board/index.php?topic=2953.0  
