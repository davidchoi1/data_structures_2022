#include <iostream>
#include <cstddef>
#include <cstdint>
#include <stdexcept>
#include <cmath>
#include <functional>

#include "heap.h"

#ifndef ANY_HEAP_H
#define ANY_HEAP_H

#define ROOT 1
#define SCALING_FACTOR 2
#define DEFAULT_SiZE 16

template<typename T>
class AnyHeap : public Heap<T>
{
public:

    // constructor with ONLY comparator paramter : initializes heap to a default size array and comparator (calling other constructor)
    AnyHeap(std::function<bool(T,T)> comparator) : AnyHeap(DEFAULT_SiZE, comparator) { }        

    /* constructor with initial size and comparator parameters : create initialize an array of initialize size 
    (starting at 1 index as root), intialize current size of array to initial size + 1, and comparator */
    AnyHeap(size_t initialSize, std::function<bool(T,T)> comparator) : itemQty{0}, store{new T[initialSize + 1]}, currentSize{initialSize + 1}, comparator{comparator} { }              

    // Given an array, array size, and comparator : initialize comparator var, copy contents of passed array into heap array, and heapify heap array 
    AnyHeap(const T array[], size_t size, std::function<bool(T,T)> comparator) : store{new T[size + 1]}, comparator{comparator}, itemQty{size}, currentSize{size}                           
    {

        for (size_t i{0}; i < size; ++i)
        {
            store[i + 1] = array[i];
        }       

        heapify(getLastParent(size));
        
    }


   // add an item to heap array
    void add(T item)                                                
    {
        if(itemQty >= currentSize)                                                                           
            resize();                                                                                       // resize if # of items in heap exceeds its current capacity

        store[++itemQty] = item;                                                                            // put item into heap at correct node and inc item quant

        upheap(itemQty >> 1);                                                                               // call upheap on parent of last leaf (order heap)   
    }

    // return root of heap
    T root()
    {
        if(itemQty == 0) throw std::runtime_error("Error: No root because heap is empty.");                 

        return store[ROOT];                                                                                 
    }

    // remove root of heap
    T remove()
    {
        T item;                                                                                             // temp var to store root
        if(itemQty == 0) throw std::runtime_error("Error: No remove because heap is empty.");               // throw if empty

        item = store[ROOT];                                                                                 // store root in temp var
        store[ROOT] = store[itemQty--];                                                                       // set root equal to last leaf index and decrement 

        downheap(ROOT);                                                                                     // downheap on root (order heap)

        return item;                                                                                   
    }

    bool empty() 
    {
        if(itemQty == 0) return true;
        return false;
    }
    // clear array
    void clear() {itemQty = 0; }      

    // return heap count
    size_t size() { return itemQty; }                                                                      

    // // return true/false based on comparison
    // bool compareTwo(T left, T right)
    // {
    //     return comparator(left, right);
    // }

private:
    T itemQty;                                                                                              // var for # of items in heap
    T *store;                                                                                               // array starting index 1
    size_t lastParent;                                                                                      // var for last parent index
    size_t currentSize;                                                                                     // var for current size of array
    std::function<bool(T,T)> comparator;                                                                    // comparator for passing in function

    // compare parent to child and return greater index
    size_t compare (size_t parentIdx)                                                                   
    {
        size_t rtnIdx{parentIdx};
        size_t lchild{parentIdx << 1};                                                                      // left child of parent = parent multiplied by 2
        size_t rchild{lchild + 1};                                                                          // right child of parent = left child plus 1
        
        if(lchild <= itemQty)
            rtnIdx = (comparator(store[parentIdx], store[lchild]) ? parentIdx : lchild);

        if(rchild <= itemQty)
            rtnIdx = (comparator(store[rtnIdx], store[rchild]) ? rtnIdx : rchild);
            
        // /* if parent index greater than heap count and parent value larger than left child value, 
        // set return index equal to parent index, other set return index equal to left child*/
        // if(lchild <= itemQty)
        //     rtnIdx = ((store[parentIdx] > store[lchild]) ? parentIdx : lchild);           
        // /* if parent index greater than heap count and return index is greater than right child,
        // set return index equal to itself, otherwise set it equal to right child */
        // if(rchild <= itemQty)
        //     rtnIdx = ((store[rtnIdx] > store[rchild]) ? rtnIdx : rchild);
 
        
        return rtnIdx;
    }
    
    // swap 2 nodes
    void swap(size_t item1Idx, size_t item2Idx)
    {
        size_t temp{store[item1Idx]};
        store[item1Idx] = store[item2Idx];
        store[item2Idx] = temp;
    }

    // 
    void upheap(size_t parentIdx)
    {

        size_t maxIdx;

        if(parentIdx < ROOT) return;
        
        maxIdx = compare(parentIdx);                       
  
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
    
        if(maxIdx == parentIdx) return; // if the max index was equal to the parent index, dont start 
        
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
        currentSize *= SCALING_FACTOR;
        T *newStore{new T[currentSize]};

        for (size_t i{ROOT}; i < itemQty; i++)                 
        {
            newStore[i] = store[i];
        }
        
        delete[] store;

        store = newStore;
    }

    void heapify(size_t lp)
    {
        for (size_t i{lp}; i >= ROOT; --i) downheap(i);
    }

};

#endif  /* MAX_HEAP_H */


// 1) tell the heap what type of heap to be (boolean function passed in{comparitor} [3 constructors(initialize size, initial size/comparitor, initial size/array)]
// 2) wrap heap with queue and use the heap to order it how we told the heap to 