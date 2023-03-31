#include<vector>

#ifndef SKIP_NODE_H
#define SKIP_NODE_H

template<typename T>
struct SkipNode
{
    T item;
    
    std::vector<SkipNode<T>*> nexts;           

    SkipNode(const T& item) : item{item} { }
    SkipNode(const T& item, SkipNode<T>* next) : item{item}, nexts{next} { }
};

#endif /* SKIPLIST_NODE */
