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
    std::ifstream in("string.dat");
    if(!in)
    {
        exit(EXIT_SUCCESS);
    }
    std::ofstream out("string2.dat", std::ios::out | std::ios::app);
    std::string record;

    while (in)
    {
        std::getline(in, record);
        if(!record.empty())
            out << record << std::endl;

    }
    
    

    return 0;
}
