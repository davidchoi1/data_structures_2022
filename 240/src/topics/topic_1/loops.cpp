#include <iostream>
#include <vector>


#define VAL 10                                              //create constant

int main(int argc, char const *argv[])
{
    //int i{10};                                                  //create variable i and initialize to 10

    //for (;;)                                                  //for loop for countdown from 10 to 1
    // {
    //     std::cout << i-- << std::endl;
    //     if(i <= 0) break;
    // }

    // while(i-- > 0)                                           //while loop for countdown 10 to 1
    // {
    //     std::cout << i-- << std::endl;
    // }

    // do                                                      //do while loop for printing 10 to 1
    // {
    //     std::cout << i << std::endl;

    // } while (i-- > 0);

 
    
    int i{};                                                // create int i initialized to default value
    std::string s{};                                        // create string s
    
    // std::cout << "Enter an integer greater than 0: ";
    // std::cin >> i;     

    std::cout << "Enter a string: ";
    std::cin >> s;     

    std::vector<int> v {1,2,3,4,5,i};                       // says no vector member of std namespace

    for (size_t i{0}; i < v.size(); ++i)
        std::cout << v[i] << std::endl;

    for (int i : v)                                       
        std::cout << i << std::endl; 

 

    
    
    return 0;
}


// g++ -E -std=c++14 -o nameof_file .\run.cpp               //what is that -E?