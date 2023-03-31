#include "HashSetQP.h"


    HashSetQP::HashSetQP(std::function<int(std::string)> h1) : h1{h1}, currentSize{DEFAULT_SIZE}, itemQty{0}
    {
        for (size_t i{0}; i < DEFAULT_SIZE; i++)
            stateArray[i] = EMPTY;
    }

    bool HashSetQP::insert(const std::string& name)
    {
        // kvpair object with string key and random value
        KVPair<std::string, int> k(name, randRange2(0, 50));
        int index = h2(h1(name));

        // resize if items exceed 60%
        if(itemQty >= (static_cast<double>(currentSize) * SCALE_WHEN))
            resize();
        
        // add item to index if empty or available
        if(stateArray[index] == EMPTY || stateArray[index] == AVAILABLE)
        {
            itemArray[index] = k;
            stateArray[index] = OCCUPIED;
            ++itemQty;
            return true;
        }

        // linear probe
        for (size_t i{0}; i < 27; i++)
        {
            if(stateArray[(index + (i*i)) % (currentSize)] == EMPTY || stateArray[(index + (i*i)) % (currentSize)] == AVAILABLE)
            {
                itemArray[(index + (i*i)) % (currentSize)] = k;
                stateArray[(index + (i*i)) % (currentSize)] = OCCUPIED;    
                ++itemQty;  
                return true;           
            }
        }
        
        return false;
    }   


    bool HashSetQP::erase(const std::string& name)
    {
        int index = h2(h1(name));

        // if element was never occupied, return false
        if(stateArray[index] == EMPTY)
            return false;

        // if element is occupied and key's match, erase
        if(stateArray[index] == OCCUPIED && itemArray[index].key == name)
        {
            stateArray[index] = AVAILABLE;
            --itemQty;
            return true;
        }

        // if element is unoccupied, but WAS occupied, linear probe 27 times to attempt find    ??no need to iterate IF it was empty right??
        if(stateArray[index] == AVAILABLE)
        {
            for (size_t i{0}; i < 27; i++)
            {
                if(stateArray[(index + (i*i)) % (currentSize)] == OCCUPIED && itemArray[(index + (i*i)) % (currentSize)].key == name)
                {
                    stateArray[(index + (i*i)) % (currentSize)] = AVAILABLE;
                    --itemQty;
                    return true;
                }
            }
        }

        return false;
    }

    const std::string* HashSetQP::find(const std::string& name)
    {
        int index = h2(h1(name));
        
        if(stateArray[index] == EMPTY)
            return nullptr;
        
        if(stateArray[index] == OCCUPIED && itemArray[index].key == name)
            return &itemArray[index].key;
        
        if((stateArray[index] == OCCUPIED && itemArray[index].key != name) ||
            stateArray[index] == AVAILABLE)
        {
            for (size_t i{0}; i < 27; i++)
            {
                if(stateArray[(index + (i*i)) % (currentSize)] == OCCUPIED && itemArray[(index + (i*i)) % (currentSize)].key == name)
                    return &itemArray[(index + (i*i)) % (currentSize)].key;
            }
        }      

        return nullptr;
    }

    size_t HashSetQP::size()
    {
        return itemQty;
    }

    bool HashSetQP::contains(const std::string& name)
    {
        int index = h2(h1(name));
        //if key element was never occupied, return false
        if(stateArray[index] == EMPTY)
            return false;
        // if key element has key we are looking for, return true
        if(stateArray[index] == OCCUPIED && itemArray[index].key == name)
            return true;
        
        // if key element is occupied and does not equal key OR key element WAS occupied, then linear probe to attempt find
        if((stateArray[index] == OCCUPIED && itemArray[index].key != name) ||
            stateArray[index] == AVAILABLE)
        {
                for (size_t i{0}; i < 27; i++)
                {
                    if(stateArray[(index + (i*i)) % (currentSize)] == OCCUPIED && itemArray[(index + (i*i)) % (currentSize)].key == name)
                        return true;
                }
        }

        return false;
    }

    void HashSetQP::resize()
    {
        size_t oldSize = currentSize;
        currentSize *= SCALING_FACTOR;
        KVPair<std::string, int>* tempItemArray{};
        KVPair<std::string, int>* newItemArray{new KVPair<std::string, int>[currentSize]};
        Status* tempStateArray{};
        Status* newStateArray{new Status[currentSize]};

        tempItemArray = itemArray;
        tempStateArray = stateArray;

        itemArray = newItemArray;
        stateArray = newStateArray;
        
        for (size_t i{0}; i < currentSize; i++)
            stateArray[i] = EMPTY;

        for (size_t i{0}; i <= oldSize; i++)                 
            insert(tempItemArray[i].key);
        
        delete[] tempItemArray;
        delete[] tempStateArray;
    }

    int HashSetQP::h2(int hashcode)
    {
       return abs(hashcode) % currentSize;
    }
