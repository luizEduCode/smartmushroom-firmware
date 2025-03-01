#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 15
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void iniciarSensorDHT() {
    dht.begin();
}

float lerTemperatura() {
    return dht.readTemperature();
}

float lerUmidade() {
    return dht.readHumidity();
}

#endif
