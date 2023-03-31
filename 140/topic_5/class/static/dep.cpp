#include <iostream>


void printVal()
{
    static int val{50};
    std::cout << val++ << std::endl;
}