#include <iostream>
#include <ctime>
#include <iomanip>


#include "skiplist.h"
#include "skipnode.h"

bool minSkip(int left, int right)
{
    return (left <= right);
}

bool maxSkip(int left, int right)
{
    return (left >= right);
}

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    Skiplist<int> skip(maxSkip);

    for (size_t i{0}; i < 50; ++i)
    {
        skip.add(i);
    }
    
    // 50 things added, should print 50
    std::cout << skip.size() << std::endl;

    // 5 added, should return true
    std::cout << std:: boolalpha;
    std::cout << skip.contains(5) << std::endl;

    // should print 19, 6, 12, 18, 9
    std::cout << skip.remove(19) << std::endl;
    std::cout << skip.remove(6) << std::endl;
    std::cout << skip.remove(12) << std::endl;
    std::cout << skip.remove(18) << std::endl;
    std::cout << skip.remove(9) << std::endl;
    std::cout << skip.remove(100) << std::endl;

    // 19 was removed, should print false
    std::cout << skip.contains(19) << std::endl;

    // 100 was never added, should call runtime error
    std::cout << skip.remove(100) << std::endl;




    return 0;
}
