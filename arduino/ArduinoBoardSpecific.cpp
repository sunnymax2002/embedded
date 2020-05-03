/*
 * Implements Arduino specific functions defined in BoardSpecific.h
 */

#include "BoardSpecific.h"
#include "Arduino.h"

inline void mS_delay(uint64_t delay) {
    delay(delay);   // Calls delay() defined by Arduino.h
}

inline void mS_timestamp() {
    millis();      // Calls millis() defined by Arduino.h
}