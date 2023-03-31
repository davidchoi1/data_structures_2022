#include "common.h"

#ifndef PERSON_H
#define PERSON_H

struct Person
{
    size_t id;
    size_t floor;

    Person() = default;
    Person(size_t id, size_t floor) : id{id}, floor{floor}

    bool operator==(const Person& other) { return id == other.id; }         // ??what the hell is going on here??
    
};

#endif