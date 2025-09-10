#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>

void ota_setup();
void ota_loop();

#ifndef STASSID
#define STASSID "NetRDS ext"
#define STAPSK "constructor"
extern const char* ssid;
extern const char* password;
#endif
