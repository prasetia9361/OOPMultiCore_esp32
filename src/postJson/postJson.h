#include <Arduino.h>
#ifndef POSTJSON_H
#define POSTJSON_H
#include <ArduinoJson.h>
#include <HTTPClient.h>
class postJson {
   private:
    HTTPClient http;
    // String token = "fgIvgz7hc2M3Ax2jMkTEAtB7eskf6prU";
    StaticJsonDocument<200> doc;
    const char* serverUrl = "http://154.62.108.192:3001/monitoringdata/";

   public:
    postJson();
    void createTemp(float data);
    void createVoltage(float data);
    void createCurrent(float data);
    void createSpeed(float data);
    void createLat(float data);
    void createLon(float data);
    void createTeam();
    // void serialJson(int size);
    void sendingJsonPost();
};
#endif