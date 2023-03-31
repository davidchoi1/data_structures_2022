#include <functional>
#include "elevator.h"




Elevator::Elevator(Floor floors[], bool callset[]) 
    : floors{floors}, callset{callset}, currentFloor{LOBBY},
      currentDir{STILL}, currentState{IDLE} { }

void Elevator::update()
{
    switch (currentState)
    {
    case IDLE:
        idle();
        break;
    case DELIVER:
        deliver();
        break;
    case PICKUP:
        pickup();
    }
}

void Elevator::idle()
{
    currentDir = STILL;
    if(noneWaiting()) return;

    if (currentFloor == LOBBY)
        currentState = (callset[LOBBY]) ? DELIVER : PICKUP;
    else
        currentState = (waiting(LOBBY + 1, TOP_FLOOR) >= 0) ? PICKUP : DELIVER;

}

size_t Elevator::waiting(size_t floor) { return callset[floor] ? floor : -1; }

size_t Elevator::waiting(size_t start, size_t end)
{
    int step = (start > end) ? -1 : 1;

    while(start != end)
    {
        if(callset[start]) return start;
        start += step;
    }

    return (callset[start]) ? start : -1;
    
}

void Elevator::deliver()
{
    
}

void Elevator::pickup()
{
    
}

bool Elevator::noneWaiting()                         
{
    for (size_t i = 0; i < FLOOR_QTY; ++i)
    {
        if(callset[i]) return false;
    }

    return true;
}

