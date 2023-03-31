#include <stdexcept>

#include "list_error.h"
#include "list.h"

#ifndef TEST_LIST_H
#define TEST_LIST_H

template<typename T>
void testAdd(List<T>* list, const T& testItem)
{
    if(list->size() != 0) std::cout << "FAILED: QUANTITY NOT 0 BEFORE ADD\n";
    list->add(testItem);
    if(list->size() != 1) std::cout << "FAILED: QUANTITY NOT 1 AFTER ADD\n";

    std::cout << "PASSED: TEST ADD\n";

}

template<typename T, size_t S>
void testAddMultiple(List<T>* list, const std::array<T, S>& array)
{
    for(const T& t : array) list->add(t);

    if(list->size() != array.size()) std::cout << "FAILED: QTY NOT THE SAME A QTY OF ADDED ITEMS\n";

    std::cout << "PASSED: TESTADDMULTIPLES\n";
}

template<typename T>
void testRemove(List<T>* list, const T& testItem)
{
    list->add(testItem);
    T rtnItem{list->remove()};
    if(testItem != rtnItem) std::cout << "FAILED: RETURN DID NOT RETURN THE CORRECT ITEM\n";
    if(list->size() != 0) std::cout << "FAILED: RETURN DID CHANGE THE LIST SIZE\n";
    if(list->contains(0)) std::cout << "FAILED: LIST STILL CONTAINS SPECIFIC ITEM REMOVED\n";

    std::cout << "PASSED: TESTREMOVE\n";
}

template<typename T, size_t S>
void testRemoveSpecific(List<T>* list, const std::array<T,S>& array)
{
    for(const T& t : array) list->add(t);

    T rtnItem{list->remove(array[array.size() - 1])};

    if(rtnItem != array[array.size() - 1]) std::cout << "FAILED: LIST DID NOT RETURN THE SPECIFIC ITEM REMOVED\n";

    if(list->size() != array.size() - 1) std::cout << "FAILED: REMOVE SPECIFIC ITEM DID NOT CHANGE THE LIST SIZE\n";

    if(list->contains(array[array.size() - 1])) std::cout << "FAILED: LIST STILL CONTAINS SPECIFIC ITEM REMOVED\n";

    try
    {
        list->clear();
        list->remove(0);

        std::cout << "FAILED: DID NOT THROW EXCEPTION ON REMOVE FROM AN EMPTY LIST.\n";
    }
    catch(const ListError& e) { }
    

    std::cout << "PASSED: TESTREMOVESPECIFIC\n";

}

template<typename T, size_t S>
void testResize(List<T>* list, const std::array<T,S>& array)
{
    for(const T& t : array) list->add(t);
    for(const T& t : array) list->add(t);
    for(const T& t : array) list->add(t);
    for(const T& t : array) list->add(t);

    if(list->size() != array.size() * 4) std::cout << "FAILED: LIST FAILED TO RESIZE";
    
    std::cout << "PASSED: TESTRESIZE\n";
}

#endif