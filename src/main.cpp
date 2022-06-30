#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#include "LittleFS.h"
#include "filesystem.h"
#include "network.h"
#include "halt.h"

Filesystem filesystem;
Network network();
// setup different subsystems (maybe fix later with one-off classes)

bool setup_websockets() {
    Serial.println("INFO: starting websockets");
    return true;
}

void setup() {
    Serial.begin(115200);
    Serial.println("\n\n3D Printer Control");

    if (!setup_websockets()) halt();

    Serial.println("Ready...");
}

void loop() {}