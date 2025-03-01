#include "config.h"
#include "wifi_manager.h"
#include "dht_sensor.h"
#include "api_client.h"
#include "parameters.h"  // Agora os parâmetros podem ser usados

const int ledPin = 2;
unsigned long previousMillis = 0;
const long interval = 3600000;  // Atualizar parâmetros a cada 1 hora

void setup() {
    Serial.begin(115200);
    conectarWiFi();   // Conecta ao Wi-Fi
    iniciarSensorDHT(); // Inicializa o sensor
    pinMode(ledPin, OUTPUT);
    
    obterParametros(); // Obtém parâmetros ao iniciar
}

void loop() {
    float temperatura = lerTemperatura();
    float umidade = lerUmidade();

    if (isnan(temperatura) || isnan(umidade)) {
        Serial.println("Erro na leitura do DHT!");
        return;
    }

    Serial.printf("Temp: %.2f°C, Umid: %.2f%%\n", temperatura, umidade);

    // Controla o LED baseado nos limites atualizados
    digitalWrite(ledPin, (temperatura < tempMin || temperatura > tempMax || umidade < umidMin || umidade > umidMax) ? HIGH : LOW);

    enviarDados(temperatura, umidade);

    // Atualiza os parâmetros a cada 1 hora
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        obterParametros();
    }

    delay(60000);  // Espera 1 minuto para nova leitura
}
