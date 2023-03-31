#include "person.h"
#include "bag.h"
#include "array_bag_6.h"
#include "common.h"

#ifndef ELEVATOR_H
#define ELEVATOR_H

#define CAPACITY 6


class Elevator
{
public:

    Elevator(Floor* floors, bool* callSet) : floors{floors}, callSet{callSet} { }  
    

    void update()                                                    
    {
        switch (eStatus)
        {
        case DROPOFF: // means we are in motion to drop off at floors
                // if destFloor > elevatorPos -> moveup() {4 ticks}
                // if destFloor = elevatorPos -> movedown() {4 ticks}
                // destFloor = findDestfloor(DROPOFF);

                while(floorPos != destFloor)        // until elevator reaches destination
                {
                    if(destFloor > floorPos)
                    {
                        if (timer == 4) {                                              
                            timer = 0;
                            moveUp();
                        } else {
                            ++timer;
                        } 
                    } else if (destFloor < floorPos) {
                        if (timer == 4) {           // keeps elevator at floor for 10 ticks before unload                                         
                            timer = 0;
                            moveDown();
                        } else {
                            ++timer;
                        } 
                    }
                }               
            
            // if destFloor = elevatorPos -> UNLOADING
            estatus = UNLOADING;
    
            break;
        case PICKUP: // means we are in motion to pick up from lobby or floors
                // if destFloor > elevatorPos -> moveup() {4 ticks}
                // if destFloor < elevatorPos -> movedown() {4 ticks}
                // destFloor = findDestfloor();

                while(floorPos != destFloor)        // until elevator reaches destination
                {
                    if(destFloor > floorPos)
                    {
                        if (timer == 4) {                                              
                            timer = 0;
                            moveUp();
                        } else {
                            ++timer;
                        } 
                    } else if (destFloor < floorPos) {
                        if (timer == 4) {           // keeps elevator at floor for 10 ticks before unload                                         
                            timer = 0;
                            moveDown();
                        } else {
                            ++timer;
                        } 
                    }
                }
                
                // if destFloor = elevatorPos -> LOADING
                eStatus = LOADING;

            break;
        case TOLOBBY: // means we are in motion to go to lobby
            // if elevatorIsNotEmpty -> UNLOADING
            // if elEmpty() -> IDLE
            if(elEmpty == false)
                eStatus = UNLOADING;
            eStatus = IDLE;

            break;
        case IDLE:  // means elevator is empty
            // if no callset presents true floor -> IDLE
            /* if at lobby && lobby callset true -> LOADING
            if at lobby && lobby callSet false -> find destFloor -> PICKUP */
            if(floorPos == LOBBY)
            {
                if(callSet[LOBBY] == true)
                    eStatus = LOADING;

                destFloor = findDestFloor(PICKUP);
                eStatus = PICKUP;
            }
            // if at floor && callset true -> find destFloor(pickup) -> PICKUP
            if(floorPos != LOBBY)
            {

                for (size_t i{FLOOR_QTY - 1}; i >= LOBBY; --i)
                {
                    if(callSet[i] == true)
                        {
                            destFloor = i;
                            eStatus = PICKUP;
                            break;
                        }
                }               
            }
                        
            break;
        case LOADING: // means we are taking persons into elevator until floor elEmpty or elevator elFull {10 ticks}
            if (timer == 10) {         // keeps elevator at floor for 10 ticks before unload                                         
                timer = 0;
                loadFrom();
            } else {
                ++timer;
            } 
            // if at lobby && elevator isNotEmpty -> find destFloor(DropOff) -> DROPOFF
            // if at lobby && elevator elEmpty -> find destFloor(PickUp) -> PICKUP
            if(floorPos == LOBBY && elEmpty() == false)
            {
                destFloor = findDestFloor(DROPOFF);
                eStatus = DROPOFF;
            }
            if(floorPos == LOBBY && elEmpty() == true)
            {
                destFloor = findDestFloor(PICKUP);
                eStatus = PICKUP;
            }
            // if at floor && (elevator elFull || callSet elEmpty()) -> TOLOBBY
            if(floorPos != LOBBY && (elFull() == true || callEmpty() == true))
            {
                eStatus = TOLOBBY;
            }
            // if at floor && elevator isNotEmpty -> find destFloor -> PICKUP
            if(floorPos != LOBBY && elEmpty() == false)
            {
                destFloor = findDestFloor(PICKUP);
                eStatus = PICKUP;
            }
            
            break;
        case UNLOADING: // means we are putting persons into floor until elevator elEmpty, or elevator no more assFloor persons in elevator bag {10 ticks}
            if (timer == 10) {         // keeps elevator at floor for 10 ticks before unload                                         
                timer = 0;
                unloadTo();
            } else {
                ++timer;
            } 
            // if at lobby && elevator isNotEmpty -> UNLOAD until Empty
            while(true)
            {
                if(floorPos == LOBBY && elEmpty() == false)
                {
                    if (timer == 10) {         // keeps elevator at floor for 10 ticks before unload                                         
                        timer = 0;
                        unloadTo();
                    } else {
                        ++timer;
                    } 
                }
                break;
            }
            // if elevator elEmpty -> IDLE
            if(elEmpty() == true)
                eStatus = IDLE;
            // if at floor && elevator isNotEmpty -> find destFloor -> DROPOFF
            if(floorPos != LOBBY && elEmpty() == FALSE)
            {
                destFloor = findDestFloor(DROPOFF);
                eStatus = DROPOFF;
            }

            break;
        }
    }

private:
    ArrayBag<Person*> elevatorBag;                                                                                                      
    ELEVATOR_STATUS eStatus{IDLE};                                                                  // elevator's status set to default idle state
    size_t timer{0};                                                                                // timer variable set to default 0 value
    size_t floorPos{LOBBY};                                                                         // floorPos set to default position LOBBY
    size_t destFloor{LOBBY};                                                                        // destination floor set to default position of LOBBY
    Floor* floors;                                                                                  // pointer array of floor objects    
    bool* callSet;                                                                                  // pointer array of callset

    // check entire callset to see if anyone wants to be picked up
    bool callEmpty()                                                                                
    {  
        size_t counter{0};

        for (size_t i{LOBBY}; i < FLOOR_QTY; ++i)
        {
            if(callSet[i] == true)
                return false;
        }

        return true;   
    }

    // check if elevator is empty
    bool elEmpty()
    {
        if(elevatorBag.size() == 0)
            return true;
        
        return false;
    }

    // check if elevator is full
    bool elFull()
    {
        if(elevatorBag.size() == 6)
            return true;
        
        return false;
    }

    // set floor position up one
    void moveUp()
    {
        ++floorPos;
    }

    // set floor position down one
    void moveDown()
    {
        --floorPos;
    }

    // dequeue from floor's elevator queue and add into elevator's bag
    void loadFrom()
    {
        elevatorBag.add(floors[floorPos].dequeue);
    }

    // ??remove person from elevator's bag and add to floor's bag??
    void unloadTo(Person* p)
    {
        floors[floorPos].add(elevatorBag.remove(/*scanbag*/));
    }

    // returns the highest floor at which someone is waiting to be picked up
    size_t highestCallSet()
    {
        size_t store{LOBBY};
    
        // scan through callset and check which ones are set[maybe put the true ones into an array?]
        for (size_t i{LOBBY}; i < FLOOR_QTY; ++i)
        {
            if(callSet[i] == true && i > store)
            {
                store = i;
            }
        }  
 
        return store;
    }

    size_t scanBag(/*floor index*/)
    {
        //scan elevator bag for person with that floors index as assFloor
        //return the pointer to that person
    }


    // scan elevator's bag for lowest assigned floor and return that floor
    size_t lowestAssFloor()
    {
        size_t store{0};

        for (size_t i{0}; i < elevatorBag.size(); ++i)
        {
            if(elevatorBag[i] < elevatorBag[i+1])                           // do I need a bounds check here??
            {
                store = i;
            }
        }  

        return store;
    }


    // returns destination floor of elevator based on status of elevator
    size_t findDestFloor(ELEVATOR_STATUS status)
    {
        size_t destFloor{0};
        // if elevator_status = DROPOFF -> destFloor = scanBag() (lowest assfloor)
        if(status == DROPOFF)
            return destFloor = lowestAssFloor();

        // if elevator_status = PICKUP -> destFloor = callSet[] (highest callSet)
        if(status == PICKUP)
           return destFloor = highestCallSet();
    }



};

#endif


