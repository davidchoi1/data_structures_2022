#include "dog.h"
#include "pet.h"

Dog::Dog(const std::string& name) : Pet("Dog", name) {}     //??Constructor dog class takes in 

std::string Dog::speak()                            // 
{
    return name + " says woof";
}