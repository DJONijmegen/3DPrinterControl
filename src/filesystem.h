#pragma once

#include <Arduino.h>
#include <LittleFS.h>

class Filesystem {
private:

public:
    Filesystem(void);
    File open(const String &);
};