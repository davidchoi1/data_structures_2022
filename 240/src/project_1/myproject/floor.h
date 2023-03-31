#include "person.h"
#include "bag.h"
#include "array_bag.h"
#include "queue.h"
#include "array_queue.h"
#include "common.h"
#include "elevator.h"

#ifndef FLOOR_H
#define FLOOR_H

class Floor
{
public:

    // synchronize callset of building and floor
    void setCallSet(bool* callset)
    {
        callSet = callset;
    }

    // add person to floor's bag
    void add(Person* p)
    {
        floorBag.add(p);
    }


    void update()
    {
        /* if bag isn't empty and 1.5% chance met, remove random person from 
        floor bag and place into elevator queue */
        if(floorBag.size() != 0 && isProbable(LEAVE_PROB))
        {
            elevatorQueue.enqueue(floorBag.misplace());
            // ?is this where I set the callset for the floor? callSet = true?
        }
    }


private:
    bool* callSet;                                                  // pointer to callset
    ArrayBag<Person*> floorBag;                                     // floor's bag to take in person objects
    ArrayQueue<Person*> elevatorQueue;                              // floor's elevator queue
};

#endif