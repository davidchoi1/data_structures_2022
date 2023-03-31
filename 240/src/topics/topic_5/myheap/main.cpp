#include <iostream>
#include "anyheap.h"
#include "priority_queue.h"

#define TEST_SIZE 8
#define BE 2
#define MAX 3
#define MIN 1

struct Anode
{
    int estCost;
    Anode(int estCost) : estCost{estCost} {}
}
;
bool
minHeap(Anode left, Anode right)
{
    return (left.estCost < right.estCost);
}

bool maxHeap(Anode left, Anode right)
{
    return (left.estCost > right.estCost);
}

int main(int argc, char const *argv[])
{
    Anode anode1(6);
    Anode anode2(18);
    Anode anode3(32);
    Anode anode4(42);
    Anode anode5(7);
    Anode anode6(90);
    Anode anode7(18);

    PriorityQueue<Anode> pq(minHeap);

    pq.enqueue(anode1);
    pq.enqueue(anode2);
    pq.enqueue(anode3);
    pq.enqueue(anode4);
    pq.enqueue(anode5);
    pq.enqueue(anode6);
    pq.enqueue(anode7);

        return 0;
}
