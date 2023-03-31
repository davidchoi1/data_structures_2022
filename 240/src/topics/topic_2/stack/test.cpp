#include <iostream>

#include "arrays.h"
#include "stack.h"

int main(int argc, char const *argv[])
{
    // int array[] {1,2,3,4,5};                         // declare and populate array

    Stack<int> stack;                                   // !!declare instance of a stack called stacked!!

    for (size_t i{0}; i < 10; ++i)                      // !!push 1-10 onto the stack!!
    {
        stack.push(i);
    }
    
    while (!stack.empty())                              // !!while stack is not empty..!!     
    {
        std::cout << stack.pop() << ' ';                // !!pop and cout every element in the stack!!
    }

    std:: cout << std::endl;                            // !!end!!
    


    // printArray<int, 5>(array);

    return 0;
}
