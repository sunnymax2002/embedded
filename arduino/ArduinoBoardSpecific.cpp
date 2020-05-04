/*
 * Implements Arduino specific functions defined in BoardSpecific.h
 */

#include "BoardSpecific.h"
#include "Arduino.h"

void mS_delay(uint64_t dly) {
    delay(dly);   // Calls delay() defined by Arduino.h
}

uint64_t mS_timestamp() {
    millis();      // Calls millis() defined by Arduino.h
}