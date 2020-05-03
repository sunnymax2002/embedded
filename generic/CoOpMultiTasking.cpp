/*
 * Implements functionality for Co-operating Multitasking implementation
 * This is preferred for simple, static embedded systems that need multi-tasking,
 * and run on less capable H/W, such as Arduino
 */

#include "BoardSpecific.h"
#include "CoOpMultiTasking.h"

CoOpTask::CoOpTask(CoOpTaskType taskType, uint64_t periodOrDelay) {
    this.type = taskType;
    this.period = periodOrDelay;
    this.state = SUSPENDED;
}

CoOpTask::Start() {
    // If task not already running
    if(this.state != ACTIVE) {
        this.lastStartTime = mS_timestamp();
    }
}

CoOpTask::Stop() {
    // Mark the state of task as STOPPED
    this.state = STOPPED;
}

bool CoOpTask::isTimeToRun() {
    if(this.state == ACTIVE) {
        uint64_t currTime = mS_timestamp();
        if(currTime >= this.lastStartTime + this.period) {
            // Update and return true
            this.lastStartTime = currTime;
            
            if(this.type == RUN_ONCE) {
                this.state = STOPPED;
            }

            return true;
        }
    } else {
        return false;
    }
}

CoOpTask::~CoOpTask() {
}