#include<stdexcept>

#include "queue.h"

#ifndef QUEUE_BAG
#define QUEUE_BAG

#define DEFAULT_SIZE 10
#define SCALING_FACTOR 2
#define QUEUE_FRONT 0

template<typename T>
class ArrayQueue : public Queue<T>                     
{
public:
    
    ArrayQueue() : store{new T[DEFAULT_SIZE]}, currentSize{DEFAULT_SIZE} { }        //!!ArrayQueue constructor intializes store pointer with array of size 10 and initializes currentSize to 10!!
    
    bool enqueue(T item)
    {
        if(this->count >= currentSize)                                              //!!resize if necessary!!
            resize();
        
        if(beg = end =  -1)
            beg = end = 1;
        
        store[this->beg++] = item;                                                //!!otherwise, increase count by one and put item in store!!??what is this->telling the compiler?

        ++this->count;

        return true;
    }

    T dequeue()
    {
        T val = front();                                                           //%%set temp equal to front value

        ++beg;

        if(beg == end)
            end %= currentSize;
        
        --this->count;                                                              //%%decrement count%%

        return val;                                                                //%%return the front value%%
    }

    T front()
    {
        if(empty()) 
            throw std:: runtime_error("It's empty bruv");                           //!!if queue is empty, throw error!!

        return store[beg];                                                          //%%just return the front value%%
    }

    bool empty()
    {
        if(this->count == 0)                            
            return true;
        
        return false;
    }

    void clear()
    {
        this->count = 0;
    }

private:
    T *store;
    T beg{-1};
    T end{-1};

    size_t currentSize;                                                             //!!value to keep track of the current size of the array!!

    void resize()                                                                   // !!helper function to resize array!!
    {
        currentSize *= SCALING_FACTOR;                                              // !!set current size equal to current size * the scaling factor to make predictably bigger!!
        T *newStore{new T[currentSize]};                                            // !!create pointer to new array with scaled size!!
        
        for (size_t i{0}; i < this->count; ++i)                                     // !!iterate through the bag!!
            newStore[i] = store[i];                                                 // !!move everything in old array to newly scaled array!!

        delete[] store;                                                             // !!delete memory address of old array!!

        store = newStore;                                                           // !!replace memory address of old array with new array!!
    }
};
#endif