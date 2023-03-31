#include <list>
#include <functional>
#include "BSTree.h"

#ifndef SET_H
#define SET_H

enum mergeType
{
    UNION,
    INTERSECTION
};

template <typename T>
class Set
{
public:
    Set(std::function<bool(T, T)> comparator) : itemQty{0}, comparator{comparator} {}

    bool insert(const T &item)
    {
        if (BST.insert(item))
        {
            ++itemQty;
            return true;
        }
        return false;
    }

    bool erase(const T &item)
    {
        return BST.erase(item);
    }

    bool erase(size_t pos)
    {
        return BST.erase(pos);
    }

    void clear()
    {
        BST.clearPost(BST.root);
        itemQty = 0;
    }

    size_t size()
    {
        return itemQty;
    }

    // how do I do this returning a pointer?
    std::list<T> toSequence()
    {
        BST.list.clear();
        BST.enSequence(BST.root);
        std::list<T> list{BST.list};
        return list;
    }

    static Set<T> leh_union(Set<T> a, Set<T> b, std::function<bool(T, T)> comparator)
    {

        a.BST.enSequence(a.BST.root);
        b.BST.enSequence(b.BST.root);

        std::list<T> cList;
        Set<T> leh_set{comparator};

        merge(a.BST.list, b.BST.list, cList, UNION);

        for (auto i : cList)
        {
            leh_set.insert(i);
        }

        return leh_set;
    }

    static Set<T> intersection(Set<T> a, Set<T> b, std::function<bool(T, T)> comparator)
    {
        a.BST.enSequence(a.BST.root);
        b.BST.enSequence(b.BST.root);

        std::list<T> cList;
        Set<T> leh_set{comparator};

        merge(a.BST.list, b.BST.list, cList, INTERSECTION);

        for (auto i : cList)
        {
            leh_set.insert(i);
        }

        return leh_set;
    }

private:
    std::function<bool(T, T)> comparator;
    std::list<T> list;
    BSTree<T> BST{comparator};
    size_t itemQty;

    static void merge(std::list<T> &A, std::list<T> &B, std::list<T> &C, mergeType myType)
    {
        auto ia = A.begin();
        auto ib = B.begin();

        while (ia != A.end() && ib != B.end())
        {
            if (*ia < *ib)
                fromA(ia++, C, myType);
            else if (*ia == *ib)
                fromBoth(ia++, ib++, C, myType);
            else
                fromB(ib++, C, myType);
        }

        while (ia != A.end())
            fromA(ia++, C, myType);

        while (ib != B.end())
            fromB(ib++, C, myType);
    }

    static void fromA(const typename std::list<T>::iterator a, std::list<T> &C, mergeType myType)
    {
        if (myType == UNION)
            C.emplace_back(*a);
        if (myType == INTERSECTION)
            ;
        return;
    }

    static void fromBoth(const typename std::list<T>::iterator a, const typename std::list<T>::iterator b, std::list<T> &C, mergeType myType)
    {
        if (myType == UNION)
            C.emplace_back(*a);
        if (myType == INTERSECTION)
            ;
        C.emplace_back(*a);
    }

    static void fromB(const typename std::list<T>::iterator a, std::list<T> &C, mergeType myType)
    {
        if (myType == UNION)
            C.emplace_back(*a);
        if (myType == INTERSECTION)
            ;
        return;
    }
};

#endif