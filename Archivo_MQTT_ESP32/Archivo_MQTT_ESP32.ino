/*
El código comienza incluyendo las bibliotecas necesarias, como WiFi.h para la conexión WiFi y PubSubClient.h para la comunicación MQTT.

A continuación, se definen algunas constantes. BUILTIN_LED representa el número de pin incorporado en el ESP32 que controla el LED integrado. ssid y password contienen el nombre de la red WiFi y la contraseña respectivamente, que se utilizarán para establecer la conexión WiFi. mqtt_server indica la dirección del servidor MQTT al que el dispositivo se conectará. Flujo1 representa el número de pin de entrada analógica utilizado para medir el valor de flujo.

Se crean objetos WiFiClient y PubSubClient para gestionar la conexión WiFi y la comunicación MQTT, respectivamente. Además, se declaran algunas variables para su posterior uso.

La función setup_wifi() se encarga de establecer la conexión WiFi. Se configura el modo de WiFi, se inicia la conexión con las credenciales proporcionadas y se espera hasta que la conexión se establezca correctamente.

La función callback() es el callback de MQTT, que se invoca cuando se recibe un mensaje en un determinado tema. En esta función, se muestra por el puerto serie el tema y el contenido del mensaje recibido. Si el primer byte del mensaje es '1', se apaga el LED integrado; de lo contrario, se enciende.

La función reconnect() se encarga de restablecer la conexión MQTT en caso de que se pierda. Intenta conectarse al broker MQTT utilizando un identificador de cliente único y, si la conexión se establece correctamente, se suscribe a un tema y publica un mensaje en otro.

En la función setup(), se configura el pin del LED integrado como salida, se inicia la comunicación serie y se llama a la función setup_wifi() para establecer la conexión WiFi. A continuación, se configura el servidor MQTT y se define la función de callback.

En la función loop(), se lee el valor de la entrada analógica Flujo1. Si no hay una conexión MQTT activa, se llama a la función reconnect() para restablecerla. Luego, se invoca client.loop() para mantener la comunicación MQTT y se verifica si ha transcurrido suficiente tiempo desde el último mensaje publicado. Si ha pasado el tiempo requerido, se incrementa el valor de value, se convierte el valor de flujo leído a una cadena de caracteres y se publica en el tema "outTopic". 
Finalmente, se muestra el mensaje por el puerto serie. El bucle se repite continuamente para mantener el funcionamiento del programa.
*/

// Librerias
#include <WiFi.h>
#include <PubSubClient.h>

// Definiciones de pines
#define BUILTIN_LED 2

// Credenciales de WiFi
const char* ssid = "ProyectosElectronica";
const char* password = "proyectos";

// Servidor MQTT
const char* mqtt_server = "broker.emqx.io";

// Pin de entrada analógica
const int Flujo1 = 34;

// Clientes de WiFi y MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// Variables
unsigned long lastMsg = 0;
char msg[50];
char msg2[50];
float value = 0;

// Función para configurar la conexión WiFi
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

// Función de callback de MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("] ");
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  
  Serial.println();

  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);
  } else {
    digitalWrite(BUILTIN_LED, HIGH);
  }
}

// Función para reconectar MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.print("Intentando conexión MQTT...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("Conectado");
      client.publish("outTopic", "T1");
      client.subscribe("inTopic");
    } else {
      Serial.print("Falló, rc=");
      Serial.print(client.state());
      Serial.println(" Intentando nuevamente en 5 segundos");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  delay(1000);
}

void loop() {
  int flowValue1 = analogRead(Flujo1);

  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    dtostrf(flowValue1, 5, 2, msg2);
    char message[50];
    snprintf(message, sizeof(message), "El valor de flujo es: %s", msg2);
    Serial.println(message);
    client.publish("outTopic", msg2);
  }
}
