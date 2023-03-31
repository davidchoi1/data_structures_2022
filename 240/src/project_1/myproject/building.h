#include "common.h"
#include "floor.h"
#include "elevator.h"

#ifndef BUILDING_H
#define BUILDING_H

class Building
{
public:

    // building constructor (?don't need to initialize any values?)
    Building()
    {
        // all elements of callSet array set to false in beginning
        for (size_t i{0}; i < FLOOR_QTY; ++i)                                              
        {
            callSet[i] = false;
        }

        // initialize all floors' callsets to false
        for (size_t i{0}; i < FLOOR_QTY; ++i)                                       
        {
            floors[i].setCallSet(callSet);        
            // ? do I need to specify which element callset?? callSet[i]?                                                              
        }

    }

    // add passed person to lobby's elevator queue
    void addPerson(Person p) 
    { 
        floors[LOBBY].elevatorQueue.enqueue(p); 
        callSet[LOBBY] = true;
    }

    // call update on elevator and floor objects
    void update()
    {
        elev.update();
        floors.update();  
        
                                                     
    }


private:
    Floor floors[FLOOR_QTY];                                            // array of floor objects
    bool callSet[FLOOR_QTY];                                            // array of callset
    Elevator elev{floors, callSet};                                     // when you want elevator to do something, call function on elev  
}


#endif