# Task States

```mermaid
stateDiagram-v2
    r : READY
    a : ACTIVE
    w : WAITING
    c : COMPLETE

    [*] --> r : Create Task
    r --> a : Activated
    a --> w : Waiting for Dependency
    w --> r : Dependency Fullfilled

    a --> c : Task Complete
    c --> [*] : Delete Task

    a --> r : Timeout
```

State | Description
---|---
READY | Task is ready to be activated, after being:<br>a. creation<br>b. timeout<br>c. dependency fullfilled
ACTIVE | Task is currently active and running on one of the worker xPU
WAITING | Task has a dependency that is not yet fulfilled, e.g. a pending memory access response, and hence task execution has suspended
COMPLETE | Task has completed executing and has therefore been suspended. However, the task creator has not yet consumed the task output, or deleted the task