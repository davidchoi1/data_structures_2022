#include <list>
#include <iomanip>
#include <iostream>
#include <ctime>
#include "set.h"

#define TEST_SIZE 50

bool minSet(int left, int right)
{
    return (left < right);
}

bool maxSet(int left, int right)
{
    return (left > right);
}

int randRange(int start, int end)
{
    return (rand() % (end - start + 1)) + start; //
}

void testMax()
{
    Set<int> max{maxSet};
    int randomNum{0};
    std::list<int> maxList;
    // test add and toSequence(max list)
    std::cout << "Max list should print: ";
    for (size_t i{0}; i < TEST_SIZE; ++i)
    {
        randomNum = randRange(1, 100);
        if (max.insert(randomNum))
            std::cout << randomNum << " ";
    }
    std::cout << "in order." << std::endl;

    maxList = max.toSequence();

    std::cout << "The ordered max print: ";
    for (auto i : maxList)
        std::cout << i << " ";
        
}

void testMin()
{
    Set<int> min{minSet};
    int randomNum{0};
    std::list<int> minList;
    // test add and toSequence(max list)
    std::cout << "Min list should print: ";
    for (size_t i{0}; i < TEST_SIZE; ++i)
    {
        randomNum = randRange(1, 100);
        if (min.insert(randomNum))
            std::cout << randomNum << " ";
    }
    std::cout << "in order." << std::endl;

    minList = min.toSequence();

    std::cout << "The ordered min print: ";
    for (auto i : minList)
        std::cout << i << " ";

    std::cout << std::endl;
}

void testErases()
{
    Set<int> set{maxSet};
    int randomNum{0};    
    std::list<int> list;
    std::list<int> deleteList;

    for (size_t i{0}; i < TEST_SIZE; ++i)
        set.insert(randRange(1, 100));

    list = set.toSequence();

    std::cout << "Items in the set are: ";
    for (auto i : list)
        std::cout << i << " ";
    std::cout << std::endl;

    for (size_t i{0}; i < 10; ++i)
        set.erase(i);
    std::cout << "Print set with last 10 elements deleted: ";
    deleteList = set.toSequence();
    for (auto i : deleteList)
        std::cout << i << " ";
}

void testUnionIntersect()
{
    int randomNum{0};
    Set<int> set1(maxSet);
    Set<int> set2(maxSet);
    Set<int> uSet(maxSet);
    Set<int> iSet(maxSet);
    std::list<int> list1;
    std::list<int> list2;
    std::list<int> uList;
    std::list<int> iList;

    
    for (size_t i{0}; i < 25; ++i)
        set1.insert(randRange(0, 100));
    list1 = set1.toSequence();
    std::cout << "Items in set 1 are: ";
    for (auto i : list1)
        std::cout << i << " ";
    std::cout << std::endl;
    
    for (size_t i{0}; i < 25; ++i)
        set2.insert(randRange(0, 100));
    list2 = set2.toSequence();
    std::cout << "Items in set 2 are: ";
    for (auto i : list2)
        std::cout << i << " ";
    std::cout << std::endl;

    uSet = Set<int>::leh_union(set1, set2, maxSet);
    uList = uSet.toSequence();
    std::cout << "The union of the sets are: ";
    for (auto i : uList)
        std::cout << i << " ";
    std::cout << std::endl;
    
    iSet = Set<int>::intersection(set1, set2, maxSet);
    iList = iSet.toSequence();
    std::cout << "The intersection of the sets are: ";
    for (auto i : iList)
        std::cout << i << " ";
    std::cout << std::endl;

}

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    testMax();
    std::cout << std::endl;
    
    testMin();
    std::cout << std::endl;
    
    testErases();
    std::cout << std::endl;
    
    testUnionIntersect();
    std::cout << std::endl;
    
}
