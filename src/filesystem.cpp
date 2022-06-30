#include "filesystem.h"
#include "halt.h"

Filesystem::Filesystem(void) {
Serial.println("INFO: mounting LitteFS");
    if (!LittleFS.begin()) {
        Serial.println("ERROR: mounting LittleFS failed!");
        halt();
    }
}

File Filesystem::open(const String &name) {
    Serial.printf("INFO: reading '%s'\n", name.c_str());
    File handle = LittleFS.open(name, "r");
    if (!handle) {
        Serial.printf("ERROR: could not open '%s' for reading\n", name.c_str());
        halt();
    }
    return handle;
}

