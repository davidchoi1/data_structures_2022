#include <cstddef>

#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
public:
    virtual bool enqueue(T item) = 0;                   // ??does this need to be set to 0??
    virtual T dequeue() = 0;                            // ??is T appropriate, is being set equal to 0 appropriate??WHY??
    virtual T front() = 0;                              
    virtual bool empty() = 0;     
    virtual void clear() = 0;                           // ??did I do all this right??

    Queue() : count{0} { }                              // !!initialize count to 0!!

protected:                                              // ??when should we use private vs public??
    size_t count;                                       // !!use unsigned integer size_t so it's never negative!!
};
#endif