#include "common.h"
#include "set.h"
#ifndef HASH_SETLP_H
#define HASH_SETLP_H

template<typename T>
class HashSetLP : public Set<T>
{
public:
    HashSetLP(std::function<int(T)> h1) : h1{h1}, currentSize{DEFAULT_SIZE}, itemQty{0}
    {
        for (size_t i{0}; i < DEFAULT_SIZE; i++)
            c[i].status = EMPTY;
    }

    bool insert(const T& item)
    {

        Common<T> k(item);
        int index = h2(h1(item));

        //resize if item quantity exceeds 60% of capacity
        if(itemQty >= (static_cast<double>(currentSize) * SCALE_WHEN))
            resize();

        // if subscript element is empty or available, occupy with item
        if(c[index].status == EMPTY || c[index].status == AVAILABLE)
        {
            c[index] = k;
            ++itemQty;
            return true;
        }

        // if subscript element neither empty nor available, linear probe
        for (size_t i{0}; i < PROBE_MAX; i++)
        {
            if(c[(index + i) % (currentSize)].status == EMPTY || c[(index + i) % (currentSize)].status == AVAILABLE)
            {
                c[(index + i) % (currentSize)] = k;
                ++itemQty;  
                return true;           
            }
        }
        
        return false;
    }

    bool erase(const T& item)
    {
        int index = h2(h1(item));

        // if element was never occupied, return false
        if(c[index].status == EMPTY)
            return false;

        // if element is occupied and key's match, erase
        if(c[index].status == OCCUPIED && c[index].key == item)
        {
            c[index].status = AVAILABLE;
            --itemQty;
            return true;
        }

        // if element is unoccupied, but WAS occupied, linear probe 27 times to attempt find    ??no need to iterate IF it was empty right??
        if(c[index].status == AVAILABLE)
        {
            for (size_t i{0}; i < PROBE_MAX; i++)
            {
                if(c[(index + i) % (currentSize)].status == OCCUPIED && c[(index + i) % (currentSize)].key == item)
                {
                    c[(index + i) % (currentSize)].status = AVAILABLE;
                    --itemQty;
                    return true;
                }
            }
        }

        return false;
    }

    const T* find(const T& item)
    {
            int index = h2(h1(item));
        
        if(c[index].status == EMPTY)
            return nullptr;
        
        if(c[index].status == OCCUPIED && c[index].key == item)
            return &c[index].key;
        
        if((c[index].status == OCCUPIED && c[index].key != item) ||
            c[index].status == AVAILABLE)
        {
            for (size_t i{0}; i < 27; i++)
            {
                if(c[(index + i) % (currentSize)].status == OCCUPIED && c[(index + i) % (currentSize)].key == item)
                    return &c[(index + i) % (currentSize)].key;
            }
        }      

        return nullptr;
    }

    bool contains(const T& item)
    {
            int index = h2(h1(item));
        //if key element was never occupied, return false
        if(c[index].status == EMPTY)
            return false;
        // if key element has key we are looking for, return true
        if(c[index].status == OCCUPIED && c[index].key == item)
            return true;
        
        // if key element is occupied and does not equal key OR key element WAS occupied, then linear probe to attempt find
        if((c[index].status == OCCUPIED && c[index].key != item) ||
            c[index].status == AVAILABLE)
        {
                for (size_t i{0}; i < 27; i++)
                {
                    if(c[(index + i) % (currentSize)].status == OCCUPIED && c[(index + i) % (currentSize)].key == item)
                        return true;
                }
        }

        return false;
    }

    size_t size()
    {
        return itemQty;
    }

private:
    std::function<int(T)> h1;
    size_t currentSize;
    size_t itemQty;
    Common<T>* c{new Common<T>[DEFAULT_SIZE]};

    int h2(int hashcode)
    {
        return abs(hashcode) % currentSize;
    }

    void resize()
    {
        itemQty = 0;
        size_t oldSize = currentSize;
        currentSize *= SCALING_FACTOR;
        Common<T>* tempc{};
        Common<T>* newc{new Common<T>[currentSize]};

        tempc = c;
        c = newc;

        for (size_t i{0}; i < currentSize; i++)
            c[i].status = EMPTY;

        for (size_t i{0}; i <= oldSize; i++)                 
            insert(tempc[i].key);
        
        delete[] tempc;
    }
};

#endif