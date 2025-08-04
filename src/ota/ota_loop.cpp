#include "ota/ota.h"

void ota_loop() {
  ArduinoOTA.handle();
}
