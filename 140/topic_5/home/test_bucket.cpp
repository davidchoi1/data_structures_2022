#include <iostream>
#include <iomanip>

#include "bucket.h"

#define TEST_SIZE 50
int main(int argc, char const *argv[])
{
    Bucket bucket;

    // populate bucket with 50 elements -> Tests Resize and Add
    for (size_t i{0}; i < TEST_SIZE; i++)
        bucket.add(i);
    
    // test count (Should print 50)
    std::cout << bucket.count() << std::endl;

    // remove 6 and 49, and test contains (Should print false, true, false, and 48)
    bucket.remove(6);
    bucket.remove();
    std::cout << std::boolalpha << bucket.contains(6) << " "
              << bucket.contains(7) << " " << bucket.contains(49) 
              << " " << bucket.count() << std::endl;

    // test frequency, add 5 2's (Should print 6)
    for (size_t i{0}; i < 5; i++)
        bucket.add(2);
    
    std::cout << bucket.getFrequency(2) << std::endl;
    
    // test clear (Should print 0 and then throw exception for trying to remove on empty bucket)
    bucket.clear();
    std::cout << bucket.count() << std::endl;
    bucket.remove();
    

    return 0;
}

// program should print
/*
50
false, true, false, 48
6
0
ERROR: Attempted remove on empty bucket.
*/