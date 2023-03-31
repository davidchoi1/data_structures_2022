#include <iostream>

int main(int argc, char const *argv[])
{
    int* a{nullptr};                                                                                // always initialize pointer to null

    for(size_t i{0}; i < argc; ++i)
        std::cout << argv[i] << std::endl;
    
    return 0;
}
