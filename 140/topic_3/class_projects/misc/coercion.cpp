#include <iostream>
#include <cstdlib>
#include<ctime>



void funct(short s)
{
    std::cout << s << std::endl;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    unsigned int v{65535}; // 0xffffffff
    funct(v);                                       // turn this int into a short
    return 0;
}
