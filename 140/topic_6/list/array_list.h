#include "list_error.h"
#include "list.h"
#include "test_list.h"

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#define DEFAULT_SIZE 16
#define SCALING_FACTOR 2

template <typename S>
class ArrayList : public List<S>
{
public:

    ArrayList() : ArrayList{DEFAULT_SIZE} { }

    ArrayList(size_t initialSize) : currentSize{initialSize}, store{new S[initialSize]}, itemQty{0} { }



    void add(const S& item)
    {
        if(itemQty >= currentSize) resize();

        store[itemQty++] = item;
    }

    S remove(const S& item)
    {
        if(empty()) throw ListError("ERROR: Attempted remove on empty list!");

        S temp;

        for (size_t i{0}; i < itemQty; ++i)
            if(store[i] == item) 
            {
                temp = store[i];
                store[i] = store[--itemQty];
                return temp;
            }
        
        throw ListError("ERROR: Item not found!");
        
    }

    S remove()
    {
        if(empty()) throw ListError("ERROR: Attempted remove on empty list!");

        return store[--itemQty];
    }

    bool contains(const S& item) const 
    {
        for (size_t i{0}; i < itemQty; ++i)
            if (store[i] == item) return true;
        
        return false;
    }

    size_t size() const 
    {
        return itemQty;
    }

    bool empty() const 
    {
        return itemQty == 0;
    }

    void clear()
    {
        itemQty = 0;
    }



private:
    size_t itemQty;
    size_t currentSize;
    S* store;
    
    void resize()
    {
        currentSize *= SCALING_FACTOR;
        S *newStore{new S[currentSize]};

        for (size_t i{0}; i < itemQty; ++i)
            newStore[i] = store[i];

        delete[] store;

        store = newStore;
    }

};



#endif