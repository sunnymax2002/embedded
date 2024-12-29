/*
 * TODO:
*/

#ifndef SCHED_H_
#define SCHED_H_

#include <stdint.h>

class Task {
public:
    typedef enum {
        READY,          // Tasks initialized to READY state, or changes to READY from WAITING
        ACTIVE,         // Active tasks are the ones which can be 'run', or stopped
        STOPPED         // Indicates that a task was started and then stopped
    } State;

private:
}
#endif // SCHED_H_