#include "pet.h"

#ifndef DOG_H
#define DOG_H


class Dog : public Pet
{
public:
    Dog(std::string);
    Dog(std::string, uint64_t);

    std::string speak();

private:
};


#endif