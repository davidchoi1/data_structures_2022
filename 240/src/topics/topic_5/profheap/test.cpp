#include <iostream>
#include <tuple>
#include "test.h"
#include "keyvalue_pair.h"

int main(int argc, char const *argv[])
{
    Tester<KVPair<int,int>> t(                                                                                   // Tester object - pass in 2 ints and return true or false depending on comparison
        [] (KVPair<int, int> l, KVPair<int, int> r) { return l.key < r.key; }
    );                                                       

    // KVPair<int,int> p1{5, 55};
    // KVPair<int,int> p2{10, 20};

    Tester<size_t> t( [] (size_t l, size_t r) { return l < r; });
    
    std::cout << std::boolalpha;                                                                        // boolalpha - turns 0/1 into true/false

    // std::cout << t.compare({10, 20}, {5, 55}) << std::endl;

    // std::cout << (p2 < p1) << std::endl;

    std::cout << t.compareIt(4, 10);

        return 0;
}



// pass in comparitor function or intial size AND comparitor function -> for heap, we decide what it is
// constructor for the heap (dynamically resized) -> pass in initialize size
// heap will have its own template variables initialized during instantiation


// priority queue initial size and comparitor or just comparitor
// priority queue will order depending on ascending or descending


// to test, check dequeue for test