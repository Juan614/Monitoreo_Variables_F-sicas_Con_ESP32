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