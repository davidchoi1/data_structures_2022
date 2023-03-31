#include<cstddef>
#include<array>

#ifndef TRIE_NODE
#define TRIE_NODE

// S is the node's cardinality (template just takes in size of array [26])
template<size_t S>
struct TrieNode
{
    // Node without parameter defaults "isTerminal" to false
    TrieNode() : TrieNode(false) { }
    // Node with parameter to set set boolean, array of pointers set to nullptr
    TrieNode(bool isTerminal) : isTerminal{isTerminal}, nexts{nullptr} { }

    // is a node is deleted then all of its decendants are deleted
    ~TrieNode() 
    {
        for (auto p : nexts)
            if(p)
            {
                delete p;
                p = nullptr;
            }
    }

    bool isLeaf()
    {
        for(const auto& n : nexts)
            if(n != nullptr) return false;
        return true;
    }

    bool isTerminal;
    std::array<TrieNode*,S> nexts;
};

#endif /* TRIE_NODE */
