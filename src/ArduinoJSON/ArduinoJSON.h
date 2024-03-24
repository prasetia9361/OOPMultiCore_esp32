#include <Arduino.h>
#ifndef ARDUINOJSON_H
#define ARDUINOJSON_H
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
class ArduinoJSON {
   private:
    HTTPClient& http;
    String token = "fgIvgz7hc2M3Ax2jMkTEAtB7eskf6prU";
    StaticJsonDocument<200> doc;
    const char* serverUrl = "http://154.62.108.192:3001/monitoringdata/";

   public:
    ArduinoJson();
    void createTemp(float data);
    void createVoltage(float data);
    void createCurrent(float data);
    void createSpeed(float data);
    void createLat(float data);
    void createLon(float data);
    void createTeam(token);
    void serializeJson(int size);
    void sendingJsonPost();
};
#endif