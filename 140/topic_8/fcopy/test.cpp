#include <iostream>
#include <sstream>
#include <string>
#include <array>
#include "fcopy.h"


int main(int argc, char const *argv[])
{   
    FCopy fcopy;
    std::string source;
    std::string dest;
    std::cout << "Enter input file name: " << std::endl;
    std::getline(std::cin, source);
    std::cout << "Enter ouput file name: " << std::endl;
    std::getline(std::cin, dest);
    
    fcopy(source, dest);
        
    return 0;
}
