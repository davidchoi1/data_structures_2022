#include "dog.h"

    Dog::Dog(std::string name) : Pet{name, "Canine"} {}

    Dog::Dog(std::string name, uint64_t id) : Pet{name, "Canine", id} {}

    std::string Dog::speak() { return "woof!"; }

