/**
Este código muestra cómo leer y mostrar los valores de dos potenciómetros analógicos utilizando Arduino y el monitor serial.
El código comienza definiendo dos constantes, Flujo1 y Flujo2, que representan los pines analógicos utilizados para leer los potenciómetros. En este caso, Flujo1 está asociado al pin 34 y Flujo2 al pin 32.
En la función setup(), se inicializa la comunicación con el monitor serial a una velocidad de 9600 baudios y se espera un segundo (1000 milisegundos) para que Arduino se estabilice.
La función loop() se ejecuta continuamente en un bucle infinito. En cada iteración del bucle, se lee el valor de los potenciómetros utilizando la función analogRead(). El valor leído se almacena en las variables flowValue1 y flowValue2 respectivamente.
A continuación, se muestra el valor de cada potenciómetro en el monitor serial utilizando las funciones Serial.print() y Serial.println(). Esto permite visualizar los valores en la interfaz de comunicación serial.
Después de mostrar los valores, se agrega un retardo de 1000 milisegundos (1 segundo) utilizando la función delay() antes de que se repita el ciclo.
En resumen, este código muestra cómo leer los valores de dos potenciómetros analógicos y mostrarlos en el monitor serial utilizando Arduino. Es útil para monitorear y visualizar la entrada analógica en tiempo real.
*/

// Variables fisicas
const int Flujo1 = 34;
const int Flujo2 = 32;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  //Leer el valor de los potenciometros
  int flowValue1 = analogRead(Flujo1);
  int flowValue2 = analogRead(Flujo2);

  //Mostrar el valor del potenciometro
  Serial.print("Valor de flujo 1: ");
  Serial.println(flowValue1);
  Serial.print("Valor de flujo 2: ");
  Serial.println(flowValue2);


  delay(1000);
}