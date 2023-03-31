#include "HashSet_LP.h"
#include "HashSet_QP.h"
#include "h1_functions.h"

void testHash();

int main(int argc, char const *argv[])
{
    testHash();
    
    return 0;
}

void testHash()
{
    HashSetQP<int> hashQPInt(h1Int);                                // hashQP object

    for (int i{0}; i < 1000; i++)
    {
        hashQPInt.insert(i);                                        // insert 1000 ints
    }

    // test size
    std::cout << hashQPInt.size() << std::endl;                                 

    // test contains
    std::cout << std::boolalpha << hashQPInt.contains(100) << std::endl;         // should contain 100, return true
    std::cout << std::boolalpha << hashQPInt.contains(1001) << std::endl;        // should not contain 1001, return false

    // test find
    std::cout << hashQPInt.find(100) << std::endl;                               // should return reference address 
    std::cout << hashQPInt.find(1001) << std::endl;                              // should return 0

    //test erase
    std::cout << std::boolalpha << hashQPInt.erase(100) << std::endl;                              // should erase and return true
    std::cout << std::boolalpha << hashQPInt.erase(1001) << std::endl;                             // should attempt erase and return false
    std::cout << hashQPInt.find(100) << std::endl;                                                 // since erase, should return null
}