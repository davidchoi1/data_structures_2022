#include <string>

#include "trie_node.h"
#include "set.h"

#ifndef TRIE_H
#define TRIE_H

#define ALPHABET_SIZE 26

class Trie : public Set<std::string>
{
public:
    bool insert(std::string item)
    {
        // iterating node so we don't lose root's spot
        TrieNode<ALPHABET_SIZE> *currentNode = root;

        // for every character in the string to be added...
        for (auto i : item)
        {

            i = tolower(i);
            if (currentNode->nexts.at(i - 'a') == nullptr)
            {
                TrieNode<ALPHABET_SIZE> *childNode = new TrieNode<ALPHABET_SIZE>;
                currentNode->nexts.at(i - 'a') = childNode;
            }

            currentNode = currentNode->nexts.at(i - 'a');
        }

        return currentNode->isTerminal = true;
    }

    bool erase(std::string item)
    {
        return true;
    }

    bool contains(std::string item)
    {
        TrieNode<ALPHABET_SIZE> *currentNode = root;

        for (auto i : item)
        {
            i = tolower(i);
            if (currentNode->nexts.at(i - 'a') == nullptr)
                return false;
            
            currentNode = currentNode->nexts.at(i - 'a');
        }

        return currentNode->isTerminal;
    }

private:
    TrieNode<ALPHABET_SIZE> *root = new TrieNode<ALPHABET_SIZE>;
};

#endif