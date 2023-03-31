#include <iostream>

int main(int argc, char const *argv[])
{
    int a{20};
    int &b{a};

    int* c{&a};                                                         // pointer c holds the address of variable a

    ++(*c);

    std::cout << *c;

    return 0;
}