#include <iostream>
#include <array>
#include <cstdlib>
#include <algorithm>

void printArray(std::array<int, 5>&);
void randomizeArray(std::array<int, 10>&);
void swap(int& a, int& b)
{
    int t{a};
    a = b;
    b = t;
}

int main(int argc, char const *argv[])
{
    std::array<int, 10> a{1,2,3,4,5,7,8,9,10,11};                                            // templated array class <datatype, arraysize> 

    // randomizeArray(a);
    std::cout << a.at(15) << std::endl;
    for(int i : a) std::cout << i << " ";
    std::cout << std::endl;
    // int array[3][3]{1,2,3,4,5,6,7,8,9};
    // for (size_t i{0}; i < 3; i++)

    //     for (size_t j{0}; j < 3; j++)
    //     {
    //         std::cout << array[i][j] << std::endl;
    //     }
        
}

                                                                                        // how do we do bounds checking using standard array again?

void printArray(std::array<int, 5>& array)
{
    for(int i : array)
        std::cout << i << std::endl;
}

void randomizeArray(std::array<int, 10>& array)
{
    for (size_t i{0}; i < 100000; i++)
    {
        swap(array[rand() % array.size()], array[rand() % array.size()]);
    }
    
}
