/*
 * TODO:
*/

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>

class Scheduler {
public:
    /*
     * Create THE scheduler, which runs on core0
    */
    Scheduler(int numWorkers);

    /*
     * Create a new task to be scheduled for execution
    */
    void createTask();

    /*
     * Inform scheduler that the active task is now waiting for dependency
     * This will usually be called on an interrupt when a specific worker issues external memory access, and hardware detects the same and informs which worker XPU issued the memory access
    */
    void onWaitForDependency(int workerId);

    /*
     * Inform scheduler that the dependency for waiting task is now fulfilled
    */
    void onDependencyFulfilled(int taskId);

    /*
     * Inform scheduler that timeout for active task on specified worker has occured
    */
    void onTaskTimeout(int workerId);

private:
    struct Worker {
        int id;         // XPU ID for worker
        bool isIdle;    // Is the worker idle
    };

    /*
     * Member elements of Scheduler
    */
    int id;
};
#endif // SCHEDULER_H_