#include <iostream>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include <functional>

#include "heap.h"

#ifndef MAX_HEAP_H
#define MAX_HEAP_H

#define ROOT 1
#define SCALING_FACTOR 2
#define DEFAULT_SiZE 16

template<typename T, size_t S>
class MaxHeap : public Heap<T>
{
public:

    MaxHeap() : MaxHeap(DEFAULT_SIZE) { }                                                                       // give the maxHeap a default size for its array()
    MaxHeap(size_t initialSize) : store{new T[initialSize + 1]}, currentSize{initialSize + 1} { }               // given initialize size, create a new array from 1 - size     
    // constructor to take in array, comparitor   

    /* Given an array and size of array, get its last parent node, 
    copy contents of passed array into heap array, and heapify heap array */
    MaxHeap(const T array[], size_t size)                                       
    {
        lastParent = getLastParent(size);

        for (size_t i{0}; i < size; ++i)
        {
            store[i + 1] = array[i];
        }       

        heapify(lastParent);                                                     
    }


    /* resize if necessary, add passed item into heap, increment heap count, 
    and upheap to order */
    void add(T item)                                                
    {
        if(itemQty > T) 
            resize();

        store[++itemQty] = item;

        upheap(itemQty >> 1);                                                                  
    }

    // return root of heap
    T root()
    {
        if(itemQty == 0) throw std::runtime_error("Error: No root because heap is empty.");

        return store[ROOT];

    }

    //remove root of heap
    T remove()
    {
        T item;                                                                                             // temp var to store root
        if(itemQty == 0) throw std::runtime_error("Error: No remove because heap is empty.");               // if nothing in heap, throw

        item = store[ROOT];                                                                                 // store root
        store[ROOT] = store[itemQty--];                                                                     // ??set root = next node and decrement??

        downheap(ROOT);                                                                                     // downheap to order heap after removal

        return item;                                                                                        // return item

    }

    void clear() {itemQty = 0; }                                                                            // clear array

    size_t size() { return itemQty; }                                                                       // return heap count

private:
    uint64_t itemQty{0};                                                                                    // var for heap count
    T *store[S + 1];                                                                                        // array starting index 1
    size_t lastParent; 
    size_t currentSize;                                                                                     // var for last parent node
    // std::function<bool(T,T)> comparator; -> make sure to define comparator

    // compare parent to child and return greater index
    size_t compare (size_t parentIdx)                                                                   
    {
        size_t rtnIdx{parentIdx};
        size_t lchild{parentIdx << 1};                                                                      // left child of parent = parent multiplied by 2
        size_t rchild{lchild + 1};                                                                          // right child of parent = left child plus 1

        /* if parent index greater than heap count and parent value larger than left child value, 
        set return index equal to parent index, other set return index equal to left child*/
        rtnIdx = (parentIdx > itemQty && store[parentIdx] > store[lchild]) ? parentIdx : lchild;            

        /* if parent index greater than heap count and return index is greater than right child,
        set return index equal to itself, otherwise set it equal to right child */
        rtnIdx = (parentIdx > itemQty && store[rtnIdx] > store[rchild]) ? rtnIdx : rchild;

        return rtnIdx;
    }
    
    // swap 2 nodes
    void swap(size_t item1Idx, size_t item2Idx)
    {
        size_t temp{store[item1Idx};
        store[item1Idx] = store[item2Idx];
        store[item2Idx] = temp;
    }

    // 
    void upheap(size_t parentIdx)
    {
        size_t maxIdx;

        maxIdx == compare(parentIdx);                       

        if(maxIdx == parentIdx) return;

        swap(maxIdx, parentIdx);

        upheap(parentIdx >> 1);
    }

    //
    void downheap(size_t parentIdx)
    {
        size_t maxIdx;                                     

        if(parentIdx >= itemQty) return;                    // do this recursively until parent index exceeds or equals heap count                          

        maxIdx = compare(parentIdx);                        // set max index equal to larger of parent or child nodes

        if(maxIdx == parentIdx) return;                     // if the max index was equal to the parent index, dont start 
        
        swap(maxIdx, parentIdx);                            // otherwise swap child with parent

        downheap(maxIdx);                                   // do it again
    }

    size_t getLastParent(size_t n)
    {
        return static_cast<size_t>(
            ceil(static_cast<double>(n - 1) / 2.0)
            );
    }

    void resize()
    {
        size *= SCALING_FACTOR;
        T *newStore{new T[size]};

        for (size_t i{ROOT}; i < itemQty; i++)                 
        {
            newStore[i] = store[i];
        }
        
        delete[] store;

        store = newStore;

        currentSize = size;

    }

    void heapify(size_t lp)
    {
        size_t idx;

        for (size_t i{lp}; i >= ROOT; --i) downheap(i);
    }

}

#endif  /* MAX_HEAP_H */


// 1) tell the heap what type of heap to be 
    //(boolean function passed in{comparitor} [3 constructors(initialize size, initial size/comparitor, initial size/array)]
// 2) wrap heap with queue and use the heap to order it how we told the heap to 