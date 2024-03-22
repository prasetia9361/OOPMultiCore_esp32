#include <Arduino.h>
#ifndef MQTT_H
#define MQTT_H
#include <MQTT.h>
#include <WiFi.h>
#include <WiFiClient.h>

WiFiClient net;
MQTTClient client;
class mqtt {
   private:
    /* data */
   public:
    mqtt();
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
