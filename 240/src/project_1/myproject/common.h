#include<iostream>
#include<cstdlib>
#include<ctime>

#ifndef COMMON_H
#define COMMON_H

#define FLOOR_QTY 50
#define LOBBY 0
#define SCND_FLOOR 1
#define ENTER_PROB 35
#define LEAVE_PROB 15


enum ELEVATOR_STATUS
{
    DROPOFF, PICKUP, TOLOBBY, IDLE, LOADING, UNLOADING
}


int randRange(int start, int end)
{
    return (rand() % (end - start + 1)) + start;                    // mod random number by scaling factor and shift up by one to return 
}

bool isProbable(int prob)
{
    if(randRange(1, 1000) <= prob)
        return true;
    
    return false;
}

#endif

