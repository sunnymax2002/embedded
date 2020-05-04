/*
 * Implements functionality for Co-operating Multitasking implementation
 * This is preferred for simple, static embedded systems that need multi-tasking,
 * and run on less capable H/W, such as Arduino
 */

#include "BoardSpecific.h"
#include "CoOpMultiTasking.h"

CoOpTask::CoOpTask(uint8_t taskId, uint64_t periodOrDelay) {
    _taskId = taskId;
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
            return true;
        }
    } else {
        return false;
    }
}

void CoOpTask::Update(uint64_t period){
    if(_state != ACTIVE) {
        _period = period;
    }
}

// Getter functions
uint8_t CoOpTask::GetTaskId() {
    return _taskId;
}
uint64_t CoOpTask::GetTaskPeriod() {
    return _period;
}
CoOpTask::State CoOpTask::GetTaskState() {
    return _state;
}

CoOpTask::~CoOpTask() {
    // TODO check if anything needed to free the memory, especially for tasks that're decommissioned before the board switched off
}