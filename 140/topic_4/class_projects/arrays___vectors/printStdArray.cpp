#include <iostream>
#include <array>



void printArray(const std::array<int, 10>& array)
{
    std::cout << "[ ";

    for(const int& i : array)
        std::cout << i << ' ';

    std::cout << "]\n";
}


int main(int argc, char const *argv[])
{
    std::array<int, 10> a{1,2,3,4,5,6,7,8,9,0};
    printArray(a);
    return 0;
}
