/*
El código proporcionado utiliza la biblioteca ESPAsyncWebServer para crear un servidor web en una placa ESP32. La placa ESP32 es un microcontrolador de bajo costo y de bajo consumo de energía que se puede programar para realizar diversas tareas.

La función setup() se ejecuta una vez al inicio y realiza las siguientes acciones:

Inicia la comunicación serial con una velocidad de 115200 baudios, lo que permite la comunicación entre el ESP32 y un dispositivo externo, como una computadora, a través del puerto serial.
Configura el servidor web utilizando el objeto server de la clase AsyncWebServer.
Define una función anónima utilizando una lambda que se ejecutará cuando se reciba una solicitud HTTP GET en la ruta principal ("/") del servidor. Esta función genera una página HTML simple que muestra el ID de la ESP32 definido como "MiESP32ID". La página HTML se envía como respuesta al cliente que realizó la solicitud.
Inicia el servidor web llamando al método begin() del objeto server.
La función loop() se ejecuta continuamente después de que la función setup() ha terminado. En este caso, no se ha proporcionado ningún código específico para el bucle principal, por lo que está vacío. Puedes agregar tu propio código dentro del bucle para realizar acciones repetitivas o responder a eventos.

En resumen, este código configura un servidor web en la ESP32 que muestra una página HTML simple con el ID de la ESP32 cuando se accede a la dirección IP del dispositivo.
*/

#include <ESPAsyncWebServer.h>

// Definir el ID de la ESP32
#define ESP32_ID "MiESP32ID"

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);
  
  // Configurar el servidor web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body>";
    html += "<h1>ID de la ESP32: " + String(ESP32_ID) + "</h1>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  // Iniciar el servidor
  server.begin();
}

void loop() {
  // Tu código de loop aquí
}