/*
 * TODO:
*/

#ifndef TASK_H_
#define TASK_H_

#include <stdint.h>

class Task {
public:
    // Refer to README for state definition and transition
    typedef enum {
        READY,
        ACTIVE,
        WAITING,
        COMPLETE
    } State;

    /*
     * TODO: Add interface for providing function to be executed and its arguments
    */
    Task(int id);

    /*
     * Activate the task, if in ready state
    */
    void activate();

private:
    int id;
    State state;
};
#endif // TASK_H_