#include <iostream>
#include <array>

// void printArray(int a[], size_t size)
// {
//     std::cout << sizeof a << std::endl;                                         // print size of array a
//     std::cout << "[ ";                                                          // print beginning bracket
//     for (size_t i{0}; i < 20; ++i)                                              // loop through and print array numbers
//         std::cout << a[i] << std::endl;

//     std::cout << "]";                                                           // print last bracket
// }

void printArray(const std::array<int, 4> &a)
{
    std::cout << sizeof a << std::endl;  // print size of array a
    std::cout << "[ ";                   // print beginning bracket
    for (size_t i{0}; i < a.size(); ++i) // loop through and print array numbers
        std::cout << a.at(i) << ' ';

    std::cout << "]"; // print last bracket
}

// int main(int argc, char const *argv[])
// {
//     int array[20]{1, 2, 3, 4}; // declare array, array size, elements of array
//     double d{20};              //

//     std::array<int, 4> array2{1, 2, 3, 4}; // declare array with built in members?

//     // printArray(array, sizeof array >> 2);                                    // call function printArray
//     printArray(array2);

//     return 0;
// }
