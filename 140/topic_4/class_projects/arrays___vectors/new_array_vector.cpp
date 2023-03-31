#include <array>
#include <vector>
#include <iostream>


int main(int argc, char const *argv[])
{
    // std::array<int, 15> a{};
    // std::vector<int> b(5);

    // b.at(1) = 5;

    // for (int i : b)
    // {
    //     std::cout << i << std::endl;
    // }

    int a[5]{1,2,3,4,5};

    int* ptr{a};

    std::cout << *ptr << std::endl;


    
    return 0;
}
