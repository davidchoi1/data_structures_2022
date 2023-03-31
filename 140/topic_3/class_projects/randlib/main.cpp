#include <iostream>

#include "lib.h"

int main(int argc, char const *argv[])
{
    for (size_t i{0}; i < 1000; ++i)
    {
        if(probability(0.5)) break;

        int rval {randRange(1,10)};
        if(rval == 10 || rval == 1) std::cout << rval << std::endl; 
        if(rval > 10 || rval < 1) std::cout << rval << std::endl; 
    }
    
    return 0;
}
