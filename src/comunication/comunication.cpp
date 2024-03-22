#include "comunication.h"

#include <WiFi.h>
comunication::comunication() {}

void comunication::wifiAP() {
    state = true;
    WiFi.softAPdisconnect(state);
    WiFi.mode(WIFI_STA);
    Serial.println("menghubungkan ke mqtt");
    Serial.print("connecting");
}

void comunication::wifiConnect(String ssid, String pass) {
    WiFi.begin(ssid, pass);
}

bool comunication::wifiStatus() { return WiFi.status() == WL_CONNECTED; }

void comunication::wifiAPconnect(String ssid, String pass) {
    WiFi.softAP(ssid, pass);
    IPAddress IP = WiFi.softAPIP();
    Serial.println("");
    Serial.print("IP Address: ");
    Serial.println(IP);
}