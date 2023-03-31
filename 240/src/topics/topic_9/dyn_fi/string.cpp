#include <cstring>
#include <iostream>

void printString(const std::string& str)
{
    std::cout << str << std::endl;
}

int main(int argc, char const *argv[])
{
    char str[]{"these characterrs"};
    size_t strSize{strlen(str)};

    std::string str2{str};
    str2[8] = 'r';

    std::cout << str2.find("rr") << std::endl;

    const char *str3{str2.c_str()};

    std::cout << str3 << std::endl;

    std::cout << str2 + str3 << std::endl;

    printString("test");

    return 0;
}
