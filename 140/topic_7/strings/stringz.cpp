#include <iostream>
#include <sstream>
#include <fstream>

#define CASE_DIFF 32

std::string &tolower(std::string &s)
{
    for (char c : s)
        if (c >= 'A' && c <= 'Z')
            c += CASE_DIFF;

    return s;
}

std::string &toupper(std::string &s)
{
    for (char &c : s)
        if (c >= 'a' && c <= 'z')
            c -= CASE_DIFF;

    return s;
}

int main(int argc, char const *argv[])
{
    std::ifstream inf("string.dat");
    std::stringstream ss;
    uint64_t id;
    uint64_t age;
    int pos1, pos2;
    std::string record;
    std::string name;


    while (inf)
    {
        
        std::getline(inf, record);
        ss << record;

        if(!record.empty())
        {
            pos1 = record.find("\"", 0);
            pos2 = record.find("\"", pos1 + 1);

            name = record.substr(pos1 + 1, pos2 - pos1 - 1);

            std::cout << atoi(record.substr(0, pos1 - 1).c_str()) << " " 
                      << name << " " << atoi(record.substr(pos2 + 1).c_str()) 
                      << std::endl;
        }
    }

    return 0;
}
