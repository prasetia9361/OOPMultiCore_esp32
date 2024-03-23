#include <Arduino.h>
#ifndef MQTTX_H
#define MQTTX_H
#include <MQTT.h>
#include <WiFiClient.h>

class mqttx {
   private:
    MQTTClient client;
    WiFiClient &_client;

   public:
    mqttx(WiFiClient &client);
    void mqttConnect(String text);
    void mqttloop();
    bool mqttlost();
    void sendtemp(uint64_t Id, String temp);
    void sendlong(uint64_t Id, String longitude);
    void sendlat(uint64_t Id, String latitude);
    void sendspeed(uint64_t Id, String speed);
    void sendVolatge(uint64_t Id, String voltage);
    void sendCurrent(uint64_t Id, String current);
};
#endif
