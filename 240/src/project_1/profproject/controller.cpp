#include "controller.h"
#include "common.h"


Controller::Controller() : nextID{0} { }

void Controller::start()
{
    while(true)
    {
        if(isProbable(NEW_PERSON_PROBABILITY))
            building.add({nextID++, randRange(1, FLOOR_QTY - 1)});
            
        building.update();
    }
}