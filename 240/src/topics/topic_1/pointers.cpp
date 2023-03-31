#include <iostream>

#include "pointers.h"
#include "arrays.h"

int main(int argc, char const *argv[])
{

    int array[]{1,2,3,4,5};                                                        // create and populate array

    printArray<int, 5>(array);                                                     // call printArray template function

    // int *a {0};                                                                 // create pointer and initialize to null
    // int b {55};                                                                 // create int variable b and initialize to 55

    // a = &b;                                                                     // a holds the address of whatever b refers to

    // std::cout << a << " " << *a << std::endl;                                   // print out the address that a points to THEN print the value that the address holds

    // *a = 10;                                                                    // dereference pointer a and assign new value {10}

    // std::cout << a << " " << b << std::endl;

    return 0;

}

void printArray(int* array, size_t size)
{
    std::cout << "[ ";                                                          // print beginning bracket
    
    for (size_t i{0}; i < size; ++i)                                            // loop through and print array numbers
        std::cout << array[i] << ' ';

    std::cout << "]\n";                                                         // print last bracket
}

//& is the referencing variable, * is the dereferencing variable

// not working