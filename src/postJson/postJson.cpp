#include "postJson.h"

postJson::postJson() {}
void postJson::createTemp(float data) { doc["hydrogatz_temp1"] = data; }
void postJson::createVoltage(float data) { doc["hydrogatz_voltage"] = data; }
void postJson::createCurrent(float data) { doc["hydrogatz_current"] = data; }
void postJson::createLat(float data) { doc["hydrogatz_lat"] = data; }
void postJson::createLon(float data) { doc["hydrogatz_lon"] = data; }
void postJson::createSpeed(float data) { doc["hydrogatz_speed"] = data; }
void postJson::createTeam() {
    doc["team"] = "fgIvgz7hc2M3Ax2jMkTEAtB7eskf6prU";
}
// void ArduinoJSON::serialJson(int size) {
//     char jsonBuffer[size];
//     serializeJson(doc, jsonBuffer);
// }
void postJson::sendingJsonPost() {
    char jsonBuffer[512];
    serializeJson(doc, jsonBuffer);
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