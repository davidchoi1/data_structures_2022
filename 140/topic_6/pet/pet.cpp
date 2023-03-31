#include "pet.h"

Pet::Pet(std::string name, std::string species) : Pet(name, species, 0) {}

Pet::Pet(std::string name, std::string species, uint64_t id) : name{name}, species{species}, id{id} {}
