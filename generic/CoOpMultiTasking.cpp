/*
 * Implements functionality for Co-operating Multitasking implementation
 * This is preferred for simple, static embedded systems that need multi-tasking,
 * and run on less capable H/W, such as Arduino
 */

#include "BoardSpecific.h"
#include "CoOpMultiTasking.h"

CoOpTask::CoOpTask(CoOpTaskType taskType, uint64_t periodOrDelay) {
    _type = taskType;
    _period = periodOrDelay;
    _state = SUSPENDED;
}

void CoOpTask::Start() {
    // If task not already running
    if(_state != ACTIVE) {
        _lastStartTime = mS_timestamp();
    }
}

void CoOpTask::Stop() {
    // Mark the state of task as STOPPED
    _state = STOPPED;
}

bool CoOpTask::isTimeToRun() {
    if(_state == ACTIVE) {
        uint64_t currTime = mS_timestamp();
        if(currTime >= _lastStartTime + _period) {
            // Update and return true
            _lastStartTime = currTime;
            
            if(_type == RUN_ONCE) {
                _state = STOPPED;
            }

            return true;
        }
    } else {
        return false;
    }
}

CoOpTask::~CoOpTask() {
}