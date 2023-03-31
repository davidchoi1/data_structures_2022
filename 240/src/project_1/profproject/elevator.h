#include "common.h"
#include "floor.h"
#ifndef ELEVATOR_H
#define ELEVATOR_H

enum State { IDLE, DELIVER, PICKUP };
enum Direction { STILL, UP, DOWN };

class Elevator
{
public:
    Elevator(Floor[], bool[]);
    void update();

private:
    State currentState;
    Direction currentDir;
    bool* callset;
    Floor* floors;
    size_t currentFloor;

    void idle();
    void deliver();
    void pickup();
    bool noneWaiting();
    bool noneLobbyWaiting();
    size_t waiting(size_t);
    size_t waiting(size_t, size_t);
};


#endif