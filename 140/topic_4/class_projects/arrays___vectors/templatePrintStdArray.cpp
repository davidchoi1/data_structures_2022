#include <iostream>
#include <array>


// template<typename T, size_t S>
// void printArray(const T array)
// {
//     std::cout << "[ ";

//     for(const T& i : array)                                                                 // ranged based for loop for objects
//         std::cout << i << ' ';

//     std::cout << "]\n";
// }

template<typename T, size_t S>
void printArray(const T array)
{
    std::cout << "[ ";

    for (size_t i{0}; i < S; ++i)
        std::cout << array[i] << ' ';

    std::cout << "]\n";
}


int main(int argc, char const *argv[])
{
    std::array<int, 10> a{1,2,3,4,5,6,7,8,9,0};

    int b[]{1,2,3,4,5,6,7,8,9,0};

    printArray<const std::array<int, a.size()>&, a.size()>(a);                                  // passing in an array object and its size to be used as templated type T
    printArray<int*, 10>(b);
    return 0;
}
