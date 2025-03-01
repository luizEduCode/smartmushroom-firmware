# Smart Mushroom - Firmware para ESP32

## 📌 Descrição
Firmware para controle e monitoramento de temperatura, umidade e CO₂ na estufa de cogumelos, utilizando ESP32.

## 🛠 Componentes Utilizados
- ESP32
- Sensor DHT22 (Temperatura e Umidade)
- Sensor MQ-135 (CO₂)
- Módulo de relés

## ⚡ Conexões
| Componente | Pino ESP32 |
|------------|-----------|
| DHT22      | GPIO 4    |
| MQ-135     | GPIO 35   |
| Relé 1     | GPIO 13   |

## 🚀 Como Compilar e Enviar o Firmware
### 📌 Pré-requisitos:
1. Instale o **Arduino IDE**.
2. Instale a biblioteca **DHT**.
3. Configure a porta serial.

### 🔧 Passos:
1. Conecte o ESP32 ao computador.
2. Compile e envie o código via Arduino IDE.
3. Monitore a saída com `serial monitor`.

## 📜 Licença
Este projeto está sob a licença MIT.
