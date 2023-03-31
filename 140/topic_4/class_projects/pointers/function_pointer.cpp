#include <iostream>

size_t factorial(unsigned int n)
{
    if(n == 0) return 1;
    return n*factorial(n - 1);
}

void processN(unsigned int n, size_t (*process)(unsigned int))                          
{
    std::cout << process(n) << std::endl;                                               
}

int main(int argc, char const *argv[])
{
    processN(8, factorial);
                                                    
    return 0;
}
