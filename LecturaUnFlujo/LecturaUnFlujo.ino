/*
El código proporcionado es un programa básico para Arduino que muestra cómo leer el valor de un potenciómetro o sensor de flujo analógico y enviarlo a través de la comunicación serial. En el programa, se define una constante Flujo 1 que representa el número del pin analógico al que está conectado el potenciómetro o sensor. En la función setup(), se configura la comunicación serial a una velocidad de 9600 baudios y se agrega una pausa para asegurar una correcta inicialización.
En la funcion loop() se lee el valor del potenciómetro o sensor de flujo, se muestra por serial y se realiza una pausa antes de repetir el proceso. Este código es útil para proyectos que requieren la lectura de sensores analógicos y la transmisión de datos a un dispositivo externo para su visualización o procesamiento posterior.

La función loop() es otra función especial en Arduino que se ejecuta continuamente después de que la función setup() finalice. En este caso, se realiza lo siguiente:
Se lee el valor del potenciómetro o sensor de flujo conectado al pin analógico representado por la constante Flujo1. El valor leído se almacena en la variable flowValue1.
Se envía un mensaje a través de la comunicación serial utilizando Serial.print() y Serial.println(). El mensaje muestra el texto "Valor de flujo 1: " seguido del valor del potenciómetro o sensor de flujo (flowValue1).
Se introduce una pausa de 1000 milisegundos (1 segundo) utilizando delay(1000) antes de repetir el bucle nuevamente.
*/

// Variable física
const int Flujo1 = 34;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  //Leer el valor de los potenciometros
  int flowValue1 = analogRead(Flujo1);

  //Mostrar el valor del potenciometro
  Serial.print("Valor de flujo 1: ");
  Serial.println(flowValue1);

  delay(1000);
}