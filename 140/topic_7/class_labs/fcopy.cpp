#include <iostream>
#include <fstream>
#include "OpeningError.h"


void printUsage()
{
    std::cout << "Usage: fileCopy.exe <srcFilename> <dstFilename>\n";
}


void fileCopy(const std::string &srcFilename, const std::string &dstFilename)
{
    char buffer[4096];
    std::ifstream src(srcFilename, std::ios::in | std::ios::binary);
    if(!src) throw std::runtime_error("Could not open src file.");

    std::ofstream dst(dstFilename, std::ios::out | std::ios::binary);

    while(src)
    {
        src.read(buffer, sizeof(buffer));
        dst.write(buffer, src.gcount());
    }

    src.close();
    dst.close();
}


int main(int argc, char const *argv[])
{
    if(argc != 3)
    {
        printUsage();
    }
    fileCopy("peep", "poop");
    return 0;

    // char buffer[4096];
    // std::cout << sizeof(buffer);
}
