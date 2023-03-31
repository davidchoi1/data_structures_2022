#include "common.h"
#include "building.h"

    Building::Building() : callset{}, elevator{floors, callset} { }


    void Building::update()
    {
        for (size_t i{0}; i < FLOOR_QTY; ++i)
            callset[i] = floors[i].update();                                                            // each floor sets its corresponding callset element
        
        elevator.update();
    }

    void Building::add(const Person& p)
    {
        floors[LOBBY].addElevQueue(p);
    }