#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <sstream>

// bool adjMatrix[][] = 
// {
// // 0  1  2  3  4  5  6  7  8  9  10  11  12  13  14  15  16  17  18  19 
//                                                                         // 0
//                                                                         // 1
//                                                                         // 2
//                                                                         // 3
//                                                                         // 4
//                                                                         // 5
//                                                                         // 6
//                                                                         // 7
//                                                                         // 8
//                                                                         // 9
//                                                                         // 10
//                                                                         // 11
//                                                                         // 12
//                                                                         // 13
//                                                                         // 14
//                                                                         // 15
//                                                                         // 16
//                                                                         // 17
//                                                                         // 18
//                                                                         // 19

// };



int main(int argc, char const *argv[])
{
    std::ifstream inf("romania_nodes.txt");
    std::string line;
    int u;
    int v;
    int c;

    if(!inf)
        throw std::runtime_error("file not opened.");

    while (inf)
    {
        std::getline(inf, line);
        std::stringstream ss(line);
        ss >> u;
        while (ss)
        {
            ss >> v;
            ss >> c;

            if(!ss)
                break;

            std::cout << "from " << u << " to " << v << " with a cost of " << c << std::endl;
        }
        
    }
    


    inf.close();
    return 0;
}
