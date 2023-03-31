#include<iostream>

using ull = unsigned long long;                                 // ull takes the place of unsigned long long everywhere in this file

// #define cout std::cout                                          // everywhere this file sees cout, it will replace

int main(int argc, char const *argv[])
{
    // char val1{10};
    // char val2{40};

    // std::cout << (val1 << 1) << std::endl;                      // shift bits in val1 to the left once and cout
    
    ull int1;
    ull int2;

    std::cout << "enter two integers: ";
    std::cin >> int1 >> int2;
    
    std::cout << int1 + int2 << std::endl;                           // prompt and take in 2 integers, add and cout

    return 0;
}
