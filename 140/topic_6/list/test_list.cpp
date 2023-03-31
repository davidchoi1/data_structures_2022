#include <iostream>
#include <iomanip>

#include "test_list.h"
#include "list.h"
#include "array_list.h"

int main(int argc, char const *argv[])
{
    int testVal{25};

    std::array<int, 10> testVals{1,2,3,4,5,6,7,8,9,10};

    try
    {
        testAdd<int>(new ArrayList<int>(), testVal);
        testAddMultiple<int, 10>(new ArrayList<int>(), testVals);
        testRemove<int>(new ArrayList<int>(), testVal);
        testRemoveSpecific<int, 10>(new ArrayList<int>(), testVals);
        testResize<int, 10>(new ArrayList<int>(5), testVals);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    




    return 0;
}
