#include <Arduino.h>
// #include <WebServer.h>
#include <WiFi.h>
#include <WiFiClient.h>

#include "./comunication/comunication.h"
#include "./eeprom/eeprom.h"
#include "./mqttx/mqttx.h"
#include "./recived/recived.h"

WiFiClient wifiClient;

// #include "HTML.h"
eeprom prom;
comunication com;
mqttx massage(wifiClient);
recived recive(massage);
int valor;
// WebServer server(80);

#define ssid "Setting_WiFi"
#define pass "1qazxsw2"
// String ssidNew = "";
// String passNew;
String ssidWifi;
String passWifi;

uint64_t chipId;

byte msgCount = 0;
long lastSendTime = 0;  // last send time
int interval = 2000;    // interval between sends
int length = 512;

TaskHandle_t Task1;
TaskHandle_t Task2;
TaskHandle_t Task3;

void restart(void *pvParameters);
void sending(void *pvParameters);
void handleClient(void *pvParameters);

void setup() {
    Serial.begin(115200);
    Serial.println("LoRa Receiver");

    prom.setup(length);
    ssidWifi = prom.eepromSsid(0, 20);
    passWifi = prom.eepromPass(20, 50);
    // client.begin("broker.emqx.io", net);
    chipId = ESP.getEfuseMac();
    Serial.println(ssidWifi);
    Serial.println(passWifi);
    com.wifiConnect(ssidWifi, passWifi);

    recive.loraconnect();
    Serial.println("LoRa Active");

    if (!com.wifiStatus()) {
        com.wifiAPconnect(ssid, pass);
        prom.settingWifi();
        // server.on("/", handleRoot);  // Routine untuk menghandle homepage
        // server.on("/action_page", handleForm);
        // server.begin();
        xTaskCreatePinnedToCore(handleClient, "Task3", 1000, NULL, 5, &Task3,
                                0);
    } else if (com.wifiStatus()) {
        com.wifiAP();
        massage.mqttConnect(String(chipId) + "/#");
        xTaskCreatePinnedToCore(restart, "Task1", 1000, NULL, 9, &Task1, 1);
        xTaskCreatePinnedToCore(sending, "Task2", 1000, NULL, 8, &Task2, 1);
    }
}

void loop() {}

void restart(void *pvParameters) {
    while (true) {
        massage.mqttloop();  // task1
        if (massage.mqttlost()) {
            com.wifiAP();
            massage.mqttConnect(String(chipId) + "/#");
        }
        delay(20);
    }
}

void handleClient(void *pvParameters) {
    while (true) {
        prom.notConnect();
        delay(50);
    }
}

void sending(void *pvParameters) {
    while (true) {
        recive.onRecive(chipId);
        // onRecive(LoRa.parsePacket());
        delay(20);
    }
}