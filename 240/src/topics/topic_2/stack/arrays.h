#include <cstddef>
#include <iostream>
#ifndef ARRAYS_H                                                   
#define ARRAYS_H                                                   

template <typename T, size_t S>                                     // create template for printArray which can be used for printArray
void printArray(T array[])                                          // !!accepts array and prints every element!!
{
    std::cout << "[ ";
    for (size_t i{0}; i < S; i++)
        std::cout << array[i] << ' ';
    
    std::cout << "]\n";
}

#endif                                                              
