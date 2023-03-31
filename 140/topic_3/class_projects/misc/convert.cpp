#include<iostream>

int main(int argc, char const *argv[])
{
    unsigned int i{65536};
    double z{i};

    unsigned short s{i};                                                                                 // can also cast static_cast<short>(i)
    std::cout << s << std::endl;                                                                         // implicit conversion will cause data loss here, shoehorning 32 bit into 16 biteieiri

    return 0;
}
