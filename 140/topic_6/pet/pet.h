#include <string>

#ifndef PET_H
#define PET_H



class Pet
{
public:

    Pet(std::string, std::string);
    Pet(std::string, std::string, uint64_t);
    virtual std::string speak() = 0;

private:
    std::string name;
    std::string species;
    uint64_t id;
};

#endif