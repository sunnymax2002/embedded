/*
 * Definitions for Co-operative Multi-tasking implementation
 * Inspiration from https://www.forward.com.au/pfod/ArduinoProgramming/RealTimeArduino/index.html
 *      and https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
 */

typedef enum {
    PERIODIC,
    RUN_ONCE,
    RUN_ON_TRIGGER
} CoOpTaskType;

typedef enum {
    SUSPENDED,
    ACTIVE,
    STOPPED
} CoOpTaskState;

public class CoOpTask {
private:
    /* data */
    CoOpTaskType type;
    uint64_t lastStartTime;             // Timestamp when task was last started by calling Start()
    uint64_t period;         // Stores period for periodic task, and delay when to run for RUN_ONCE tasks when start() is called
    CoOpTaskState state;
public:
    CoOpTask(CoOpTaskType taskType, uint64_t period);
    ~CoOpTask();

    Start();    // Starts the task, if it is in SUSPENDED state. A periodic task runs every period mS, while RUN_ONCE task runs only once, _periodOrTimestamp mS after start() is called
    Stop();     // Stops the further execution of the task, until Start() is called again
    bool isTimeToRun();  // Checks if it is time to run the task or not
};
