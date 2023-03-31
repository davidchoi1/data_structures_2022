#include<string>

#include "pet.h"

#ifndef CAT_H
#define CAT_H

class Cat : public Pet                                              // create class instantiation of Dog from class of Pet
{
public:
    Cat(const std::string&);                                        // constructor of Dog (takes in const parameter name)
    std::string speak();                                            // Dog has string object called speak which allows it to speak
};


#endif