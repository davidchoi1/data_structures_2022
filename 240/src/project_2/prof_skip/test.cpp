#include<iostream>
#include<cstdlib>

#include"common.h"
#include"skiplist.h"

#ifdef ANALYZE
#include"analyzer.h"
#endif

#define TEST_VAL_QTY 10'000
#define TEST_VAL_SCALING_FACTOR 100'000

int main(int argc, char const *argv[])
{
    int n{TEST_VAL_QTY};

    std::vector<int> rndVals(n, 0);

    Skiplist<int> list;    
    
    while(n > 0) 
    {
        int rndval{rand() % TEST_VAL_SCALING_FACTOR};
        rndVals[n-1] = rndval;
        list.add(rndval);
        --n;
    }

    for(int v : rndVals)
        if(!list.contains(v))
            std::cout << v << " not found!\n";

#ifdef ANALYZE
    Analyzer::printList<int>(list);
    Analyzer::printMaxHeight(list);
    std::cout << "item qty = " << list.size() << std::endl;
#endif

    return 0;
}
