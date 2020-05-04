/*
 * Defines the functions used by generic code, but must be implemented specific to H/W
 */

#ifndef BOARDSPECIFIC_H_
#define BOARDSPECIFIC_H_

#include <stdint.h>

/*
 * Time related functions
 */

// Generates delay of 'delay' milli-seconds, limited by Board's clock & resolution limits. Blocking function
void mS_delay(uint64_t delay);

// Returns the current timestamp from milliseconds counter in the H/W
uint64_t mS_timestamp();

/*
 * Pin(s) related functions
 */
typedef enum {IN, OUT} PinDirection;
typedef enum {H = 1, L = 0} PinState;

// Configure pin direction and enable it
void ConfigPin(uint8_t numPin, PinDirection dir);

// Drives an output pin in digital mode (logic H/L)
void SetPin(uint8_t numPin, PinState state);

// Drives an output pin in PWM mode
void SetPinPwm(uint8_t numPin, uint64_t pwmValue);

#endif  // BOARDSPECIFIC_H_