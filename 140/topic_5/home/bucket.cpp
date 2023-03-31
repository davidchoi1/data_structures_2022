// who: Dong Choi dchoi24
// what: The Bucket
// why: Bucket
// when: 10/30/22

#include "bucket.h"



	Bucket::Bucket() : currentSize(DEFAULT_SIZE), items{new double[DEFAULT_SIZE]}, itemCount{0} { }
	

	Bucket::Bucket(const size_t size) : currentSize(size), items{new double[size]}, itemCount{0} { }
	

    size_t Bucket::count()
    {
        return itemCount;
    }


    bool Bucket::empty()
    {
        return itemCount == 0;
    }


    void Bucket::add(const double item)
    {
        if(itemCount >= currentSize)
            resize();
        
        items[itemCount++] = item;
    }


    double Bucket::remove()
    {
        if (itemCount == 0)
            throw std::runtime_error("ERROR: Attempted remove on empty bucket.");
        
        return items[itemCount--];
        
    }


    bool Bucket::remove(const double item)
    {
        if (itemCount == 0)
            throw std::runtime_error("ERROR: Attempted remove on empty bucket.");
        
        for (size_t i{0}; i < itemCount; ++i)
        {
            if(items[i] == item)
            {
                items[i] = items[itemCount--];
                return true;
            }
        }
        
        return false;
    }


    void Bucket::clear()
    {
        for (size_t i{0}; i < itemCount; ++i)
            items[i] = 0;

        itemCount = 0;
    }


    size_t Bucket::getFrequency(const double item)
    {
        size_t frequency{0};

        for (size_t i{0}; i < itemCount; ++i)
            if(items[i] == item) 
                ++frequency;
        
        return frequency;
    }


    bool Bucket::contains(const double item)
    {
        for (size_t i{0}; i < itemCount; ++i)
            if(items[i] == item)
                return true;
        
        return false;
    }

    void Bucket::resize()
    {
        currentSize *= SCALING_FACTOR;
        double *newItems{new double[currentSize]};

        for (size_t i{0}; i < itemCount; ++i)
            newItems[i] = items[i];

        delete[] items;

        items = newItems;
        
    }