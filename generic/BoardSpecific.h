/*
 * Defines the functions used by generic code, but must be implemented specific to H/W
 */

#ifndef BOARDSPECIFIC_H_
#define BOARDSPECIFIC_H_

#include <stdint.h>

/*
 * Generates delay of 'delay' milli-seconds, limited by Board's clock & resolution limits
 * Blocking function
 */
void mS_delay(uint64_t delay);

/*
 * Returns the current timestamp from milliseconds counter in the H/W
 */
uint64_t mS_timestamp();

#endif  // BOARDSPECIFIC_H_