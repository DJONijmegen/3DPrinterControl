#include <Arduino.h>
#include "LittleFS.h"

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "halt.h"
#include "filesystem.h"

#include "credentials.h"


Filesystem filesystem;

// setup different subsystems (maybe fix later with one-off classes)

bool setup_wifi() {
    Serial.println("INFO: starting WiFi");
    WiFi.begin(ssid, password);
    Serial.printf("INFO: Connecting to '%s'.", ssid);
    for (int i = 0; i < 10; i++) {
        if (WiFi.status() == WL_CONNECTED) {
            Serial.printf("INFO: Connected to '%s'.\n", ssid);
            Serial.printf("INFO: IP Address: %s\n", WiFi.localIP().toString().c_str());
            return true;
        }
        delay(500);
        Serial.print('.');
    }
    return false;
}

bool setup_websockets() {
    Serial.println("INFO: starting websockets");
    return true;
}

void setup() {
    Serial.begin(115200);
    Serial.println("\n\n3D Printer Control");

    if (!setup_filesystem()) halt();
    if (!setup_wifi()) halt();
    if (!setup_websockets()) halt();

    Serial.println("Ready...");
}

void loop() {}