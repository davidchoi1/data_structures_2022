#include "trie.h"

Trie::Trie() : root{new NODE} {}

bool Trie::insert(const std::string &word)
{
    insert(word, 0u, root);
}

bool Trie::erase(const std::string &word)
{
    if (!contains)
}

bool Trie::contains(const std::string &word)
{
    if (word.empty())
        throw TrieError("Error: Invalid argument in contains");

    char idx;
    NODE_PTR ptr{root};

    for (char c : word)
    {
        idx = c - 'a';
        if (ptr->nexts[idx] == nullptr)
            return false;
        ptr = ptr->nexts[idx];
    }

    return ptr->isTerminal;
}

bool Trie::isLeaf(const NODE_PTR node)
{
    for (const NODE_PTR i : node->nexts)
        if (i != nullptr)
            return false;

    return true;
}

bool Trie::insert(const std::string &word, int cPos, NODE_PTR node)
{
    char idx{word[cPos] - 'a'};

    if (node->nexts[idx] == nullptr)
        node->nexts[idx] = new NODE;

    if (cPos >= word.size() - 1)
    {
        node->nexts[idx]->isTerminal = true;
        return true;
    }

    return insert(word, cPos + 1, node->nexts[idx]);
}
