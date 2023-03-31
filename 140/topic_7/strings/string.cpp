#include <iostream>
#include <sstream>

#define CASE_DIFF 32

std::string& tolower(std::string& s)
{
    for (char c : s)
        if(c >= 'A' && c <= 'Z') c += CASE_DIFF;
    
    return s;
}


std::string& toupper(std::string& s)
{
    for (char& c : s)
        if(c >= 'a' && c <= 'z') c -= CASE_DIFF;

    return s;
}


int main(int argc, char const *argv[])
{
    std::string s{"21 B 45 C 85 D 57 E -1 F"};
    int i;
    char c;
    std::stringstream ss(s);

    while (ss)
    {
        ss >> i;
        ss >> c;

        if (!ss)
            break;

        std::cout << i << " " << c << std::endl;
    }
    

    return 0;
}
