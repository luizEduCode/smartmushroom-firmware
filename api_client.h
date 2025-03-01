#ifndef API_CLIENT_H
#define API_CLIENT_H

#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "config.h"

void enviarDados(float temperatura, float umidade) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(SERVER_URL_LEITURAS);
        http.addHeader("Content-Type", "application/json");

        String jsonData = "{\"temperatura\":" + String(temperatura, 2) + ",\"umidade\":" + String(umidade, 2) + "}";
        int httpResponseCode = http.POST(jsonData);

        Serial.print("Resposta do servidor: ");
        Serial.println(httpResponseCode);
        http.end();
    }
}

#endif
