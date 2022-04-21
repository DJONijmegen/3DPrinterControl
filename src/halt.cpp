// Something that leaves the system is in an known failure mode if stuff broke.

#include "halt.h"

void halt(void) {
    Serial.println("FATAL: System halted");
    for (;;)
        // Do nothing. Let the watchdog reset the system.
        ;
}