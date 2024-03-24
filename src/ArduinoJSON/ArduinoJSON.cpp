#include "ArduinoJSON.h"

ArduinoJSON::ArduinoJson() {}
void ArduinoJSON::createTemp(float data) { doc["hydrogatz_temp1"] = data; }
void ArduinoJSON::createVoltage(float data) { doc["hydrogatz_voltage"] = data; }
void ArduinoJSON::createCurrent(float data) { doc["hydrogatz_current"] = data; }
void ArduinoJSON::createLat(float data) { doc["hydrogatz_lat"] = data; }
void ArduinoJSON::createLon(float data) { doc["hydrogatz_lon"] = data; }
void ArduinoJSON::createSpeed(float data) { doc["hydrogatz_speed"] = data; }
void ArduinoJSON::createTeam() { doc["team"] = token; }
void ArduinoJSON::serializeJson(int size) {
    char jsonBuffer[size];
    serializeJson(doc, jsonBuffer);
}
void ArduinoJSON::sendingJsonPost() {
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(jsonBuffer);

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
    } else {
        Serial.print("Error in HTTP POST request: ");
        Serial.println(httpResponseCode);
    }

    http.end();
}