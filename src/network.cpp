#include "network.h"

#include "halt.h"

#include "credentials.h"

Network::Network(void) {
    Serial.println("INFO: starting Network");
    WiFi.begin(ssid, password);
    Serial.printf("INFO: Connecting to '%s'.", ssid);
    for (int i = 0; i < 10; i++) {
        if (WiFi.status() == WL_CONNECTED) {
            Serial.println();
            Serial.printf("INFO: Connected to '%s'.\n", ssid);
            Serial.printf("INFO: IP Address: %s\n", WiFi.localIP().toString().c_str());
        }
        delay(500);
        Serial.print('.');
    }
    Serial.println();
    halt();
}
