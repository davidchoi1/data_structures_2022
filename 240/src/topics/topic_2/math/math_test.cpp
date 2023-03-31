#include <iostream>
#include "math.h"

int main(int argc, char const *argv[])
{
    long x{-25};
    long y{55};

    Math<long> m(Math<long>::abs(x),y);                                                                             // instantiate math object from math class

    std::cout << "absolute value of x is: " << Math<long>::abs(x) << std::endl;                                     // print absolute value of variable passed
    std::cout << "greatest value of the two is: " << Math<long>::max(x,y) << std::endl;                             // print absolute value of variable passed

    std::cout << m.area() << std::endl;                                                                          // call area function (non-static)

    return 0;
}
