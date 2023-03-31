#include <iostream>
#include "fib.h"

int main(int argc, char const *argv[])
{
    int n{50}; // create and initialize n variable

    std::cout << nthFib(n) << std::endl; // print fib value

    // for (size_t l{0}, r{1}, t; n >= 0; --n, t = l, l = l + r, r = t)         // unconventional fibonacci sequence
    //     std::cout << l << std::endl;

    return 0;
}