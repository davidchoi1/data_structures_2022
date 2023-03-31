#include<stdexcept>

#include "bag.h"
#include"C:\Users\My Razer\Workspace\240\src\topics\node.h"

#ifndef ARRAY_BAG_H
#define ARRAY_BAG_H

#define DEfAULT_SIZE 10                                                             
#define SCALING_FACTOR 2                                                            // !!standard scaling factor for resizing bag!!

template<typename T>                                                                
class ArrayBag : public Bag<T>                                                      // ??why public??
{
public:

    ArrayBag() : store{new T[DEfAULT_SIZE]}, currentSize{DEfAULT_SIZE} { }          // ??What is this constructor initializing to??

    bool add(T item)                                                                // ??Did this inherit the virtual add??
    {
        if(this->count >= currentSize)                                              // !!If the count is greater than or equal to the current size..!!
            resize();                                                               // !!Resize bag to make room for item!!

        store[this->count++] = item;                                                // !!Otherwise, increase count by one and item in 'store'!!
                                                                                    // ??do we need to add to count after this or does the previous line handle that??
        return true;                                                                
    }

    bool remove(T item)
    {   
        int i = indexOf(item);                                                      // !!set i = index of function (call functioon indexOf to get it)!!
        if(i >= 0)                                                                  // !!if index is greater than or equal to 0...!!
        {
            store[i] = store[this->count--];                                        // ??overwrite subscript memaddress value of item with last memaddress value??
            return true;                                                            // !!break out!!
        }

        return false;                                                               // !!otherwise, return item was not found!!
    }

    bool contains(T item)                                                           
    {
        return indexOf(item) >= 0;                                                  // !!return the index of the item as long as it's greater than or equal to zero!!
    }                                                                               // ??how come we don't have a return false here??

    size_t size()                                                                   
    {
        return this->count;                                                         // !!return the count of the bag!!
    }

    T grab()
    {
        if(this->count == 0)                                                        // !!if the count of items in the bag is equal to zero (if nothing in bag)!!
            throw std::runtime_error("Grab on empty bag!");                         // !!throw a run time error exception (there is nothing in the bag bruv)!!

        return store[0];                                                            // ??otherwise, return the item in the first memaddress of bag??
    }

private:
    T *store;                                                                       // !!pointer to a place in memory called store (will act as beginning point of array)!!
    size_t currentSize;                                                             // !!size of the array to keep track of array's current size!!

    void resize()                                                                   // !!helper function to resize array!!
    {
        currentSize *= SCALING_FACTOR;                                              // !!set current size equal to current size * the scaling factor to make predictably bigger!!
        T *newStore{new T[currentSize]};                                            // !!create pointer to new array with scaled size!!
        
        for (size_t i{0}; i < this->count; ++i)                                     // !!iterate through the bag!!
            newStore[i] = store[i];                                                 // !!move everything in old array to newly scaled array!!

        delete[] store;                                                             // !!delete memory address of old array!!

        store = newStore;                                                           // !!replace memory address of old array with new array!!
    }

    int indexOf(T item)                                                             // helper function to look for item and return index of it
    {
        for (size_t i{0}; i < this->count; ++i)                                     // !!iterate through array to search for item!!
        {
            if(store[i] == item)                                                    // !!once item is found...!!
                return i;                                                           // !!return the index of it!!
        }
        return -1;                                                                  // !!otherwise return -1!!
    }

};

#endif