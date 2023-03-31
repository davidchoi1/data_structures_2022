#include <iostream>

//using std::cout; can do this and remove the std:: from line 8

int main(int argc, char const *argv[])
{
    // for(int i = 10; i >= 0; --i)
    //     std::cout << i << std::endl;                         // prints the countdown from 10 to 1 of integer i


    // std::cout << argc << std::endl;                          // prints out argc

    for(int i = 0; i < argc; ++i)
        std::cout << argv[i] << std::endl;                      // 

    return 0;
}
