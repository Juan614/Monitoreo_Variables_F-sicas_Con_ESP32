const int Flujo1 = 34;
const int Flujo2 = 32;
/*
// Variables para almacenar los valores leídos
float corriente;
float tension;

// Parámetros para la conversión de corriente a tensión
const float RESISTENCIA_CARGA = 250.0; // Resistencia de carga en ohmios
const float CORRIENTE_MIN = 4.0;      // Corriente mínima en mA
const float CORRIENTE_MAX = 20.0;     // Corriente máxima en mA
const float TENSION_MIN = 1.0;        // Tensión correspondiente a la corriente mínima en voltios
const float TENSION_MAX = 5.0;        // Tensión correspondiente a la corriente máxima en voltios
*/
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

/*
  // Solicitar la lectura de datos a la tarjeta HW-685
  Wire.beginTransmission(HW685_ADDRESS);
  Wire.endTransmission(false);
  Wire.requestFrom(HW685_ADDRESS, 2);

  // Esperar a que se reciban los datos
  if (Wire.available() == 2) {
    // Leer los dos bytes recibidos y combinarlos en un valor de corriente
    int msb = Wire.read();
    int lsb = Wire.read();
    corriente = ((msb << 8) | lsb) * 0.001;
    
    // Calcular la tensión correspondiente a la corriente medida
    tension = corriente * RESISTENCIA_CARGA;
    tension = map(tension, CORRIENTE_MIN * RESISTENCIA_CARGA, CORRIENTE_MAX * RESISTENCIA_CARGA, TENSION_MIN, TENSION_MAX);
    
    // Imprimir los valores medidos
    Serial.print("Corriente: ");
    Serial.print(corriente);
    Serial.print(" mA, Tensión: ");
    Serial.print(tension);
    Serial.println(" V");
  }

  // Esperar un segundo antes de hacer otra lectura
  */
  delay(1000);
}



/*

CONEXIONES

-Object 1
pin D34

-Object 2
pin D32

VIN +
GND -

*/