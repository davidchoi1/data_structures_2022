#include<string>

#include "pet.h"

#ifndef DOG_H
#define DOG_H

class Dog : public Pet                                              // !!class called dog which inherits pet class!!
{
public:
    Dog(const std::string&);                                        // ??Dog constructor which takes in string reference parameter for name?? What about the second parameter defined in pet call??
    std::string speak();                                            // ??Declaration of speak function with return type string??
};


#endif