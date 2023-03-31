#include <iostream>

int main(int argc, char const *argv[])
{
    int a{20};
    int* b{&a};                                                             // pointer b pointing at address of a
    int** c{&b};                                                            // pointer c is pointing to the memory address of b

    std::cout << a << " " << b << " " << c << std::endl;;

    return 0;
}
