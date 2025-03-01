#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "config.h"

// Variáveis para limites ambientais
float tempMin = 20.0;
float tempMax = 25.0;
float umidMin = 70.0;
float umidMax = 85.0;

// Função para buscar os parâmetros atualizados da API
void obterParametros() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(SERVER_URL_PARAMETROS);
        int httpResponseCode = http.GET();

        if (httpResponseCode == 200) {  // Sucesso na requisição
            String response = http.getString();
            Serial.println("Parâmetros recebidos: " + response);

            // Parse do JSON recebido
            DynamicJsonDocument doc(512);
            DeserializationError error = deserializeJson(doc, response);

            if (!error) {
                tempMin = doc["tempMin"];
                tempMax = doc["tempMax"];
                umidMin = doc["umidMin"];
                umidMax = doc["umidMax"];
                Serial.println("Parâmetros atualizados com sucesso.");
            } else {
                Serial.println("Erro ao analisar os parâmetros JSON");
            }
        } else {
            Serial.print("Erro ao obter parâmetros: ");
            Serial.println(httpResponseCode);
        }
        http.end();
    }
}

#endif
