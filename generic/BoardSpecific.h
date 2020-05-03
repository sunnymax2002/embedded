/*
 * Defines the functions used by generic code, but must be implemented specific to H/W
 */

#include <stdint.h>

/*
 * Generates delay of 'delay' milli-seconds, limited by Board's clock & resolution limits
 * Blocking function
 */
void mS_delay(uint64_t delay);

/*
 * Returns the current timestamp from milliseconds counter in the H/W
 */
void mS_timestamp();