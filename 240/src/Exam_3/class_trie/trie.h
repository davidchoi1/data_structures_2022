#include <string>
#include <stdexcept>

#include "trie_node.h"
#include "set.h"


#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

using NODE = TrieNode<ALPHABET_SIZE>;
using NODE_PTR = TrieNode<ALPHABET_SIZE>*;

class Trie : public Set<std::string>
{
public:
    Trie();
    bool insert(const std::string&);
    bool erase(const std::string&);
    bool contains(const std::string&) const;

private:
    TrieNode<ALPHABET_SIZE> root;

    bool isLeaf(const NODE_PTR);
    bool insert(const std::string&, uint32_t, NODE_PTR);
};


struct TrieError : public std::runtime_error
{
    TrieError() : std::runtime_error("Error: Invalid Trie operation") { }

    TrieError(const char* msg) : std::runtime_error(msg) { }
}

#endif