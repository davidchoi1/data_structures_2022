#include <iostream>
#include <cstring>
#include "stack.h"

int main(int argc, char const *argv[])
{
    std::string s{"suzy peepee'd and poopoo'd"};

    Stack<char, 26> stack;

    for(const char& c : s)
        stack.push(c);

        while(!stack.empty())
            std::cout << stack.pop() << std::endl;

    return 0;
}
