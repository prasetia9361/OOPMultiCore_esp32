#include "mqttx.h"

#include <iostream>
mqttx::mqttx() {}
void mqttx::mqttConnect(String text) {
    std::cout << "Method dari ClassB dipanggil" << std::endl;
    client.begin("broker.emqx.io", net);
    while (!client.connect("ESP32")) {
        Serial.print(".");
        delay(1000);
    }
    Serial.print("mqtt connected");
    client.subscribe(text);  // String(chipId) + "/#"
}

void mqttx::mqttloop() { client.loop(); }

bool mqttx::mqttlost() { return !client.connected(); }

void mqttx::sendtemp(uint64_t Id, String temp) {
    client.publish(String(Id) + "/suhu", temp);  //
    Serial.println("data suhu terkirim lewat" + String(Id) + "/suhu");
    Serial.println(temp);
    // 106151743883988/suhu
    // delay(100);
}

void mqttx::sendlong(uint64_t Id, String longitude) {
    client.publish(String(Id) + "/long", longitude);
    Serial.println("data longitude terkirim lewat" + String(Id) + "/long");
    Serial.println(longitude);
    // 106151743883988/long
    // delay(100);
}
void mqttx::sendlat(uint64_t Id, String latitude) {
    client.publish(String(Id) + "/lat", latitude);
    Serial.println("data latitude terkirim lewat" + String(Id) + "/lat");
    Serial.println(latitude);
    // 106151743883988/lat
    // delay(100);
}
void mqttx::sendspeed(uint64_t Id, String speed) {
    client.publish(String(Id) + "/speed", speed);
    Serial.println("data speed terkirim lewat" + String(Id) + "/speed");
    Serial.println(speed);
    // 106151743883988/speed
    // delay(100);
}

void mqttx::sendVolatge(uint64_t Id, String voltage) {
    client.publish(String(Id) + "/vol", voltage);
    Serial.println("data speed terkirim lewat" + String(Id) + "/vol");
    Serial.println(voltage);
    // 106151743883988/vol
    // delay(100);
}

void mqttx::sendCurrent(uint64_t Id, String current) {
    client.publish(String(Id) + "/current", current);
    Serial.println("data speed terkirim lewat" + String(Id) + "/current");
    Serial.println(current);
    // 106151743883988/current
    // delay(100);
}