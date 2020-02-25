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
Pin 3 tiene una resistencia pull-up de 1.5k  
Pin 5 no solo puede proporcionar 3V  
Esta es la correspondencia de entradas analógicas con número de pines:  
A1 P2, A2 P4, A3 P3, A0 P5  

Cómo instalar  
https://digistump.com/wiki/digispark/tutorials/connecting  
Instalación de drivers puede fallar, copiar ruta de archivo y ejecutar como administrador.  
