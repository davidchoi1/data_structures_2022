#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "queue.h"
#include "anyheap.h"

template<typename T>
class PriorityQueue : public Queue<T>
{
public:

    PriorityQueue(std::function<bool(T,T)> comparator) : h{comparator} { }

    PriorityQueue(const T array[], size_t size, std::function<bool(T,T)> comparator) : h{array, size, comparator} { }

    PriorityQueue(size_t initialSize, std::function<bool(T,T)> comparator) : h{initialSize, comparator} { }



    void enqueue(T item)
    {
        h.add(item);
    }                   

    T dequeue()
    {
        return h.remove();
    }      

    T front()
    {
        return h.root();
    }     

    bool empty()
    {
        return h.empty();
    }    

    void clear()
    {
        h.clear();
    }  

private:
    AnyHeap<T> h;



};

#endif