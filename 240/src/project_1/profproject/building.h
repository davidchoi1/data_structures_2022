#include "common.h"
#include "elevator.h"
#include "floor.h"

#ifndef BUILDING_H
#define BUILDING_H

class Building
{
public:
    Building();
    void update();
    void add(const Person&);

private:
    bool callset[FLOOR_QTY];
    Floor floors[FLOOR_QTY];
    Elevator elevator;
}


#endif 