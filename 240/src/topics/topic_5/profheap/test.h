#include<functional>
#ifndef TEST_H
#define TEST_H

template<typename T>
class Tester
{
public:
    Tester(std::function<bool(T,T)> comparator) : comparator{comparator} { }                        // constructor taking in a boolean function

    bool compareIt(T left, T right)
    {
        return comparator(left, right);                                                             // function returns boolean of comparison
    }

private:
    std::function<bool(T,T)> comparator;                    // function creator 
};

#endif /* TEST_H */