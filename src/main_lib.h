#include <iostream>
#include <string.h>
#include "blink/libraries"
#include "ota/ota.h"
#include "dis/used_headers.h"
#include <FS.h>
#include <LittleFS.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ArduinoJson.h>
#include "file_handling.h"

int ncounter=0, nindex=0;
int dcounter=0, dindex=0;
char x[100][15]={0};
char y[100][10]={0};

