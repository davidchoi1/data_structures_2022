#include <iostream>

unsigned long long fact(unsigned int);

unsigned long long fib(unsigned int);

unsigned int getInput(std::string);
void printTriangle();

int main(int argc, char const *argv[])
{
    // unsigned int n{getInput("Enter a value between 0 - 100: ")};
    // std::cout << fib(10) << std::endl;

    printTriangle();
    return 0;
}







unsigned long long fact(unsigned int n)
{
    if(n <= 1) return 1;

    return n * fact(n-1);
}

unsigned long long fib(unsigned int n)
{
    // if(n <= 1) return n;                                             // recursive

    // return fib(n - 1) + fib(n - 2);

    unsigned long long trailing{0}; // create variables of size_t datatype and initialize
    unsigned long long leading{1};
    unsigned long long temp{0};

    for (size_t i{0}; i < n; i++)
    {
        temp = leading;
        leading += trailing;
        trailing = temp;
    }

    return trailing; // return the trailing value
}

unsigned int getInput(std::string prompt)
{
    unsigned int inVal;
    std::cout << prompt;
    std::cin >> inVal;

    if(inVal <= 100) return inVal;

    std::cout << "Invald value!!\nTry again\n";
    return getInput(prompt);
}

void printTriangle()
{
    std::string s{"           \n"};
    for (size_t i{0}; i < 10; ++i)
    {
        s[i] = '*';
        std::cout << s;
    }
    
}