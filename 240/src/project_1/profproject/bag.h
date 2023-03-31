#include <cstddef>                                                      // ??what is cstddef used for??
#ifndef BAG_H                                                           // ??why is include guard needed??
#define BAG_H

template<typename T>                                                    // !!template for class named Bag (takes in parameter datatype)!!
class Bag                                                               // !!class called bag!!
{
public: 
    virtual bool add(T item) = 0;                                       // !!equaling 0 means pure virtual function (must be overriden) in implementation class!!
    virtual bool remove(T item) = 0;                                    // 
    virtual bool contains(T item) = 0;                                  // !!checks to see if item is inside bag, returns true if so, false if not!!
    virtual size_t size() = 0;                                          // 
    virtual T grab() = 0;                                               // 

    Bag() : count {0} { }                                               // !!Bag constructor initializes count to 0, meant to keep counter of items!!

protected:                                                              // !!makes count accessible by derived class using this->!!
    size_t count;                                                       /
};

#endif /* BAG_H */