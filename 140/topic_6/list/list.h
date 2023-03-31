#include<cstddef>

#ifndef LIST_H
#define LIST_H

template <typename T>
struct List
{
    
    virtual void add(const T&) = 0;
    virtual T remove(const T&) = 0;
    virtual T remove() = 0;
    virtual bool contains(const T&) const = 0;
    virtual size_t size() const = 0;
    virtual bool empty() const = 0;
    virtual void clear() = 0;

};


#endif