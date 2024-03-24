#include <Arduino.h>
#ifndef RECIVED_H
#define RECIVED_H
#include <LoRa.h>
#include <SPI.h>
// #include <WiFiClient.h>

#include "../mqttx/mqttx.h"
#include "../postJson/postJson.h"
class recived {
   private:
    // mqttx &_message(WiFiClient &_clientt);
    mqttx &_message;
    postJson &_httpPost;
    byte localAddress = 0xBB;  // address of this device
    byte destination = 0xFF;
    int ss = 5;
    int rst = 14;
    int dio0 = 2;
    unsigned long sending;
    int packetSize;
    char cadena[40];
    byte posicion = 0;
    String temp;
    String longitude;
    String latitude;
    String speed;
    String voltage;
    String current;

   public:
    // recived(mqttx &message(WiFiClient &clientt));
    recived(mqttx &message, postJson &httpPost);
    void loraconnect();
    String getValue(String data, char separator, int index);
    void onRecive(uint64_t numId);
};
#endif
