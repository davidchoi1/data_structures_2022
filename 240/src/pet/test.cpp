#include <iostream>

#include "pet.h"
#include "dog.h"
#include "cat.h"

int main(int argc, char const *argv[])
{
    Pet* pets[] {new Cat{"frisky"}, new Dog{"Fido"}};
    
    for (size_t i{0}; i < 2; i++)
    {
        std::cout << pets[i]->speak() << std::endl;
    }
               
    return 0;
}
