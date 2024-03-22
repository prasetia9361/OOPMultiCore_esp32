#include <Arduino.h>
#ifndef COMUNICATION_H
#define COMUNICATION_H

class comunication {
   private:
    // String text;
    bool state = false;
    int message;

   public:
    comunication();
    void wifiAP();
    void wifiConnect(String ssid, String pass);
    bool wifiStatus();
    void wifiAPconnect(String ssid, String pass);
};
#endif