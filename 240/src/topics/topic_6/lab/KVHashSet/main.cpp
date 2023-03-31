#include <ctime>
#include <iostream>
#include <iomanip>
#include "HashSetQP.h"


int h1(const std::string& k)
{
    int hash{0};
    const int factor{31};

    for (size_t i{0}; i < k.length(); ++i)
    {
        hash = factor * hash + k[i];
    }

    return hash;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    HashSetQP hash(h1);

    hash.insert("poop");
    std::cout << std::boolalpha << hash.find("slut") << std::endl;

    return 0;
}
