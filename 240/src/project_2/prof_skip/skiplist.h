#include <vector>

#include "skiplist_node.h"
#include "skiplist_error.h"

#ifdef ANALYZE
#include "analyzer.h"
#endif

#ifndef SKIPLIST
#define SKIPLIST

// Note: It is assumed that type T has overloded comparison operators
template <typename T>
class Skiplist
{
#ifdef ANALYZE
    friend class Analyzer;
#endif
    using NODE_PTR = SkiplistNode<T>*;
    using NODE = SkiplistNode<T>;


public:
    Skiplist() : itemQty{0}, heads{nullptr} { }

    // Adds an item into the container.
    void add(const T &item)
    {
        if(contains(item)) return;

        std::vector<NODE_PTR> search{findPreviousNodes(item)}; 
    
        NODE_PTR node{new NODE{item}};

        addNode(search, node, 0);

        ++itemQty;
    }

    // Removes and returns an item from the container
    T remove(const T& item)
    {
        NODE_PTR node{getContainingNode(item)};
        if(!node) throw SkiplistError("Remove on nonexistant item");

        std::vector<NODE_PTR> search{findPreviousNodes(item)};

        removeNode(search, node, 0);

        removeEmptyLevels();

        delete node;
        --itemQty;
        
        return item;
    }

    // Checks if item is already in the container. Returns true if it is and false otherwise
    bool contains(const T& item) const { return getContainingNode(item) != nullptr; }

    // returns the number of items stored in the set
    size_t size() const { return itemQty; }


private:
    std::vector<SkiplistNode<T> *> heads;
    size_t itemQty;

    void removeEmptyLevels()
    {
        for(int i{heads.size() - 1}; i >= 0; --i)
            if(!heads[i]) 
                heads.pop_back();
            else 
                return;
    }

    std::vector<NODE_PTR> findPreviousNodes(const T& item) const
    {
        std::vector<NODE_PTR> search(heads.size(), nullptr);
        int highestLevel{heads.size() - 1};

        for (int level{highestLevel}; level >= 0; --level)
        {
            search[level] = (level < highestLevel) 
                ? search[level + 1] 
                : nullptr;

            search[level] = (!search[level] && heads[level] && heads[level]->item < item) 
                ? heads[level] 
                : search[level];

            while(search[level] 
                  && search[level]->nexts[level] 
                  && search[level]->nexts[level]->item < item)
                search[level] = search[level]->nexts[level]; 
        }
        
        return search;
    }

    void addNode(std::vector<NODE_PTR>& search, NODE_PTR node, size_t level)
    {
        NODE_PTR next{nullptr};
        ++node->height;

        if(search[level]) next = search[level];

        if(next)
        {
            node->nexts[level] = next->nexts[level];
            next->nexts[level] = node;
        }     
        else
        {
            node->nexts[level] = heads[level];
            heads[level] = node;
        }

        if(getsPromoted()) promoteNode(search, node, level + 1);
    }

    void promoteNode(std::vector<NODE_PTR>& search, NODE_PTR node, size_t level)
    {
        if(level == heads.size())
        {
            heads.push_back(nullptr);
            search.push_back(nullptr);
        }

        node->nexts.push_back(nullptr);

        addNode(search, node, level);
    }

    void removeNode(std::vector<NODE_PTR>& search, NODE_PTR node, size_t level)
    {
        NODE_PTR prev{search[level]};

        if(prev && prev->nexts[level] == node)
            prev->nexts[level] = node->nexts[level];
        else if(heads[level] == node)
            heads[level] = node->nexts[level];
        else
            return;
        
        removeNode(search, node, level + 1);
    }

    NODE_PTR getContainingNode(const T& item) const
    {
        std::vector<NODE_PTR> search{findPreviousNodes(item)};

        while(search[0] && search[0]->item <= item)
        {
            if(search[0]->item == item) return search[0];
            search[0] = search[0]->nexts[0];
        }

        if(heads[0] && heads[0]->item == item)
            return heads[0];

        return nullptr;
    }

    bool getsPromoted() const { return static_cast<bool>(rand() & 1); }
};

#endif /* SKIPLIST */
