#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include "config.h"

void conectarWiFi() {
    Serial.print("Conectando ao WiFi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    int tentativas = 0;

    while (WiFi.status() != WL_CONNECTED && tentativas < 20) { // 20 tentativas
        delay(500);
        Serial.print(".");
        tentativas++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nConectado com sucesso!");
    } else {
        Serial.println("\nFalha ao conectar ao WiFi");
    }
}

#endif
