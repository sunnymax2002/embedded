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

void ConfigPin(uint8_t numPin, PinDirection dir) {
    pinMode(numPin, OUTPUT);
}

void SetPin(uint8_t numPin, PinState state) {
    switch (state) {
    case L:
        digitalWrite(numPin, LOW);
        return;
    case H:
        digitalWrite(numPin, HIGH);
        return;
    default:
        return; // Do nothing
    }
}

void SetPinPwm(uint8_t numPin, uint64_t pwmValue) {
    analogWrite(numPin, pwmValue);
}