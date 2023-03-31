#include <iostream>
#include <functional>

size_t factorial(unsigned int n)
{
    if(n == 0) return 1;
    return n*factorial(n - 1);
}

void processNCorrectly(unsigned int n, std::function<size_t(unsigned int)> process)                                                               
{
    std::cout << process(n) << std::endl;                                               
}

int main(int argc, char const *argv[])
{
    processNCorrectly(8, factorial);                                                             
    return 0;
}
