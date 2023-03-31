#include <iostream>


uint64_t fib(int);
uint64_t fib_dyn(int, uint64_t []);



int main(int argc, char const *argv[])
{
    const int n = 50;

    {
        uint64_t memo[n + 1]{};
        std::cout << fib_dyn(n, memo) << std::endl;
    }

    return 0;
}

uint64_t fib(int n)
{
    if(n <= 1) return n;

    return fib(n - 1) + fib(n - 2);
}

// bottom up
uint64_t fib_dyn(int n, uint64_t memo[])
{
    if(n <= 1) return n;
    
    return memo[n] = (memo[n] == 0) ? fib_dyn(n - 1, memo) + fib_dyn(n - 2, memo) : memo[n];
}

