#include <iostream>
#include "pet.h"
#include "dog.h"

int main(int argc, char const *argv[])
{
    Pet* t = new Dog("Tedders", 500);


    std::cout << t->speak() << std::endl;

    return 0;
}
