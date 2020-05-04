/*
 * Definitions for Co-operative Multi-tasking implementation
 * Inspiration from https://www.forward.com.au/pfod/ArduinoProgramming/RealTimeArduino/index.html
 *      and https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

#ifndef COOPMULTITASKING_H_
#define COOPMULTITASKING_H_

#include <stdint.h>

class CoOpTask {
public:
    /* To simplify, assuming all tasks are periodic, and can be stopped by application logic to realize run-n-times tasks
    typedef enum {
        PERIODIC,
        RUN_ONCE,
        RUN_ON_TRIGGER
    } CoOpTaskType; */

    typedef enum {
        SUSPENDED,      // Tasks initialized to SUSPENDED state to indicate it is not yet started
        ACTIVE,         // Active tasks are the ones which can be 'run', or stopped
        STOPPED         // Indicates that a task was started and then stopped
    } State;

    CoOpTask(uint8_t taskId, uint64_t period);
    ~CoOpTask();

    void Start();    // Starts the task, if it is in SUSPENDED or STOPPED state
    void Stop();     // Stops the further execution of the task, until Start() is called again
    bool isTimeToRun();  // Checks if it is time to run the task or not. Assumes that if this returns true, the application will run the task, and hence it updates the _lastStartTime
    void Update(uint64_t period);   // Updates the attributes of the task. Can only work if task is not ACTIVE
    uint8_t GetTaskId();
    uint64_t GetTaskPeriod();
    State GetTaskState();
private:
    // Removed as part of simplification: CoOpTaskType _type;
    uint8_t _taskId;    // Identifier for task. Application responsible to provide unique IDs
    uint64_t _lastStartTime;  // Timestamp when task was last started by calling Start()
    uint64_t _period;         // Stores period for task
    State _state;
};

#endif  // COOPMULTITASKING_H_