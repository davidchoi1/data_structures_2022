#include "building.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
    Controller();
    void start();

private:
    Building building;
    size_t nextID;
}


#endif