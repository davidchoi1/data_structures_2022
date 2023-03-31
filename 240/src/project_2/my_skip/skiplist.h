#include <vector>
#include <cstdlib>
#include <functional>
#include <stdexcept>
#include <iostream>

#include "skipnode.h"

#ifndef SKIPLIST_H
#define SKIPLIST_H

// Note: It is assumed that type T has overloaded comparison operators
template <typename T>
class Skiplist
{
public:
    // can I set the entirety of the nexts vector equal to nullptr??
    Skiplist(std::function<bool(T, T)> comparator) : comparator{comparator}, itemQty{0}
    {
        nexts = {nullptr};
    }

    // Adds an item into the container.
    void add(const T &item)
    {
        size_t whileCounter{1};
        // vector holds pointers previous to where item is to be inserted
        std::vector<SkipNode<T> *> sVector{searchHelper(item)};

        /* create a new node to hold item : the pointer in its vector's first element points to
           search vector's first element, which is a pointer that point's to the skiplist's vector's
           first element's pointer */
        SkipNode<T> *newNode = new SkipNode<T>(item);


        // if the returned search vector is empty... create the base level
        if (sVector.size() == 0)
        {
            newNode->nexts.push_back(nullptr);
            nexts.push_back(newNode);
        }
        // if a node, not at the end of the list, exists, and its next node is the item to be added, don't add
        else if ((sVector.at(0) != nullptr) && (sVector.at(0)->nexts.at(0) != nullptr) && (sVector.at(0)->nexts.at(0)->item == item))
        {
            return; 
        }
        // if the first node in the skip list node holds the item to be added, don't add
        else if((sVector.at(0) == nullptr) && (nexts.at(0)->item == item))
        {
            return;
        }
        // if item is smallest item at base level
        else if (sVector.at(0) == nullptr)
        {
            // put pointer to next biggest node inside new node's vector
            newNode->nexts.push_back(nexts.at(0));
            // the skiplist base level pointer points to our new node
            nexts.at(0) = newNode;
        }
        else
        {
            // put pointer to next biggest node insigned new node's vector
            newNode->nexts.push_back(sVector.at(0)->nexts.at(0));
            // previous node points to our new node
            sVector.at(0)->nexts.at(0) = newNode;
        }


        while (getsPromoted())
        {
            // resize vector if level for promotion doesn't exist
            if (nexts.size() <= whileCounter)
            {
                nexts.push_back(newNode);
                newNode->nexts.push_back(nullptr);
            }
            else if (sVector.at(whileCounter) == nullptr)
            {
                // put pointer to next biggest node inside new node's vector
                newNode->nexts.push_back(nexts.at(whileCounter));
                // the skiplist base level pointer points to our new node
                nexts.at(whileCounter) = newNode;
            }
            else
            {
                // put pointer to next biggest node insigned new node's vector
                newNode->nexts.push_back(sVector.at(whileCounter)->nexts.at(whileCounter));
                // previous node points to our new node
                sVector.at(whileCounter)->nexts.at(whileCounter) = newNode;
            }

            ++whileCounter;
        }

        ++itemQty;
    }

    // Removes and returns an item from the container
    T remove(const T &item)
    {

        std::vector<SkipNode<T> *> sVector{searchHelper(item)};
        SkipNode<T> *temp;

        if (sVector.size() == 0)
            throw std::runtime_error("ERROR : Remove on empty skiplist.");

        // 
        if ((sVector.at(0) != nullptr) && (sVector.at(0)->nexts.at(0) != nullptr) && (sVector.at(0)->nexts.at(0)->item != item))
            throw std::runtime_error("ERROR : Item doesn't exist.");

        // only one node on level and doesnt equal item
        if ((sVector.at(0) == nullptr) && (nexts.at(0)->item != item))
            throw std::runtime_error("ERROR : Item doesn't exist.");
        
        // returns last node on level
        if (sVector.at(0) != nullptr && sVector.at(0)->nexts.at(0) == nullptr)
            throw std::runtime_error("ERROR : Item doesn't exist.");


        if ((sVector.at(0) == nullptr))
        {
            temp = nexts.at(0);
        }
        else
        {
            temp = sVector.at(0)->nexts.at(0);
        }


        for (size_t i{0}; i < sVector.size(); i++)
        { 
            if (sVector.at(i) != nullptr && sVector.at(i)->nexts.at(i) == nullptr)
            {
                break;
            }
            else if ((sVector.at(i) != nullptr) && (sVector.at(i)->nexts.at(i) != nullptr) && (sVector.at(i)->nexts.at(i)->item != item))
            {
                break;
            }
            else if ((sVector.at(i) == nullptr) && (nexts.at(i)->item != item))
            {
                break;
            }
            else if ((sVector.at(i) == nullptr) && (nexts.at(i)->nexts.at(i) != nullptr))
            {
                nexts.at(i) = nexts.at(i)->nexts.at(i);
            }
            else if ((sVector.at(i) == nullptr) && (nexts.at(i)->nexts.at(i) == nullptr))
            {
                nexts.at(i) = nullptr;
            }
            else if (sVector.at(i)->nexts.at(i)->item == item)
            {
                sVector.at(i)->nexts.at(i) = sVector.at(i)->nexts.at(i)->nexts.at(i);
            }
        }

        --itemQty;
        delete temp;
        return item;
    }

    // Checks if item is already in the container. Returns true if it is and false otherwise
    bool contains(const T &item)
    {
        std::vector<SkipNode<T> *> sVector{searchHelper(item)};

        if (sVector.size() == 0)
            return false;

        if ((sVector.at(0) != nullptr) && (sVector.at(0)->nexts.at(0) != nullptr) && (sVector.at(0)->nexts.at(0)->item != item))
            return false;

        if ((sVector.at(0) == nullptr) && (nexts.at(0)->item != item))
            return false;

        return true;
    }

    // returns the number of items stored in the set
    size_t size() { return itemQty; }

private:
    std::vector<SkipNode<T> *> nexts;
    std::function<bool(T, T)> comparator;
    size_t itemQty;

    bool getsPromoted() { return static_cast<bool>(rand() & 1); }

    // return vectors of pointers previous to search item
    std::vector<SkipNode<T> *> searchHelper(const T &item)
    {
        // vector to hold pointers to all level nodes
        std::vector<SkipNode<T> *> returnVector(nexts.size());

        // leading pointer intilialized to the skiplist vector's top level pointer
        SkipNode<T> *lead{nexts.at(nexts.size() - 1)};

        // trailing vector pointing at nothing
        SkipNode<T> *prev{nullptr};

        // delete level of skiplist vector and return vector if nothing in it
        for (int i{nexts.size() - 1}; i >= 0; --i)
        {
            if (nexts.at(i) == nullptr)
            {
                nexts.pop_back();
                returnVector.pop_back();
            }
        }

        // process every level vector element from top down
        for (int i{nexts.size() - 1}; i >= 0; --i)
        {

            // iterate until nullptr or we hit item (<= or =>) to requested item
            while (lead != nullptr)
            {
                // break out of loop if leading item is < or > to search term
                if (comparator(lead->item, item))
                    break;

                // set trailing pointer to lead
                prev = lead;

                // set leading pointer to the next node
                lead = lead->nexts.at(i);
            }

            // once leading value has hit something (<= or >=), put trailing node in return vector
            returnVector.at(i) = prev;

            // if trailing pointer points at a node, set lead pointer to that value to start search from there at level below
            if (prev != nullptr)
            {
                lead = prev;
            }
            // if trailing pointer points at nothing and not at bottom level, start next lower level search at first node of of that level
            else if (prev == nullptr && i != 0)
            {
                lead = nexts.at(i - 1);
            }
        }

        return returnVector;
    }
};

#endif /* SKIPLIST */
