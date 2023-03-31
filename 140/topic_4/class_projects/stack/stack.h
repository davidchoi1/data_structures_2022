#include <iostream>
#include <array>
#include <stdexcept>

#ifndef STACK_H
#define STACK_H

template<typename T, size_t S>
class Stack
{
public:
    void push(const T& item)
    {
        if(itemQty == S) throw std::runtime_error("push on full stack");

        store[itemQty++];
    }

    T pop()
    {
        if(empty()) throw std::runtime_error("pop on empty stack");

        return store[--itemQty];

    }

    T top()
    {
        if(empty()) throw std::runtime_error("top on empty stack");

        return store[itemQty - 1];
    }

    bool empty() { return itemQty == 0; }



private:
    std::array<T,S> store{ };
    size_t itemQty{ };
};

#endif