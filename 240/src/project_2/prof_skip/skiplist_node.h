#include<vector>

#ifndef SKIPLIST_NODE
#define SKIPLIST_NODE

template<typename T>
struct SkiplistNode
{
    using NODE_PTR = SkiplistNode<T>*;

    T item;

    size_t height;

    std::vector<NODE_PTR> nexts;
    
    SkiplistNode(const T& item) : item{item}, height{0} ,nexts{nullptr} { }
};

#endif /* SKIPLIST_NODE */
