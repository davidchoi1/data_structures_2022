#include "fib.h" //

ulong nthFib(int n) // fib sequence function which takes in an int and returns a size_t
{
    ulong trailing{0}; // create variables of size_t datatype and initialize
    ulong leading{1};
    ulong temp;

    while (n >= 0) // while passed n is greater than or equal to 0, scan through fib vauess
    {
        temp = leading;
        leading += trailing;
        trailing = temp;
        --n;
    }

    return trailing; // return the trailing value
}

// compilation line for compiling :  g++ main.cpp fib.cpp -o main.exe