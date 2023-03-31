#include<string>                            // include string header

#ifndef PET_H                               // header guard
#define PET_H                               // header guard

class Pet                                   // declare class pet
{
public:
    Pet(const std::string&, const std::string&);    
    virtual std::string speak() = 0;                // !!pure virtual function with return type string, called speak!!               

protected:
    std::string species;                        // element string species of pet
    std::string name;                           // element string name of pet
};


#endif