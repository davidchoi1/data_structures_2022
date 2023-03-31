#include<iostream>
#include<stdexcept>

#include "class_queue.h"

#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#define DEFAULT_SIZE 5
#define SCALING_FACTOR 2

template<typename T>
class ArrayQueue : public Queue<T>
{
public:

    ArrayQueue() : frontidx{-1}, backidx{-1}, store{new T[DEFAULT_SIZE]}, 
        currentSize{DEFAULT_SIZE}, count{0} { }                                         // constructor intiializes frontidx and backidx index trackers to -1, points store at new object, sets current size and initializes count to 0

    void enqueue(T item)
    {
        if(count == currentSize) resize();                                                                                              // resize if array is full 
        
        ++backidx;                                                                                                                      // increment the back index
        backidx %= currentSize;                                                                                                         // mod back index with current size of array and set it equal to back index
        store[backidx] = item;                                                                                                          // place accepted item into new back index of that index of array
        ++count;                                                                                                                        // increment the count 

        if(frontidx == -1) frontidx = backidx;                                                                                           // if the front index is equal to -1, then set back index same (for empty)                                                                                   
    }               

    T dequeue()
    {
        T rtnItem{store[frontidx++]};                                                                                                   // intialize a new variable with the item at the front of the array and then increment the front

        if(empty()) throw std::runtime_error("Dequeue on empty Queue");                                                                  // if array is empty, throw

        frontidx %= currentSize;                                                                                                   

        --count;

        return rtnItem;
    }           

    T front()
    {
        if(empty()) throw std::runtime_error("Front on empty Queue");

        return store[frontidx];
    }             

    bool empty()
    {
        return count == 0;                                                                                                              // if count is equal to zero, return true, otherwise false
    }   

    void clear()
    {
        count = 0;
        frontidx = backidx = -1;                                                                                                      // set count, frontidx and backidx equal to original states to clear
    }               

private:
    size_t currentSize;
    int frontidx;
    int backidx;
    size_t count;
    T* store; 

    void resize()
    {
        size_t newSize {currentSize * SCALING_FACTOR};
        T* newStore{new T[newSize]};

        for (size_t i = 0; i < count; ++i)                                                  // iterating through the array
        {
            newStore[i] = store[frontidx];                                                  // place array item at frontidx into new array index i   
            ++frontidx;                                                                        // increment the frontidx
            frontidx %= currentSize;                                                           // mod the new frontidx with the current size of array
        }
        
        delete[] store;                                                                     // delete old array pointer array
        store = newStore;                                                                   // set new array equal to new array
        frontidx = 0;
        backidx = count - 1;
        currentSize = newSize;
    }
};

#endif