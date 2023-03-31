#include <stdexcept>
#include <functional>

#ifndef BSTREE_H
#define BSTREE_H

template <typename T>
struct BSTNode
{
    T item;

    BSTNode<T> *rightChild;
    BSTNode<T> *leftChild;

    BSTNode(const T &item) : item{item}, leftChild{nullptr}, rightChild{nullptr} {}
};

template <typename T>
struct BSTree
{
    BSTNode<T> *root;
    std::list<T> list;
    std::function<bool(T,T)> comparator;

    BSTree(std::function<bool(T,T)> comparator) : root{nullptr}, comparator{comparator} {}

    bool insert(const T &item)
    {
        if (root == nullptr)
        {
            createTree(item);
            return true;
        }

        BSTNode<T> *leafNode = searchNode(item);
        if (leafNode->item == item)
            return false;
        else if (comparator(leafNode->item, item))
        {
            leafNode->leftChild = new BSTNode<T>{item};
            return true;
        }
        else if (comparator(item, leafNode->item))
        {
            leafNode->rightChild = new BSTNode<T>{item};
            return true;
        }
    }

    bool erase(const T &item)
    {
        BSTNode<T> *lehNode = searchNode(item);
        // don't do anything if item not found
        if (lehNode->item != item)
            return false;
        lehNode = copyLete(root, item);
        return true;
    }

    bool erase(size_t pos)
    {
        
        enSequence(root);
        if(pos > list.size())
            throw std::runtime_error("Attempted erase outside of bounds!");
        auto it = list.begin();

        for (size_t i{0}; i < pos; ++i)
            ++it;

        return erase(*it);
    }

    // use recursive postOrder to delete all nodes in tree
    void clearPost(BSTNode<T> *parent)
    {
        if (parent == nullptr)
            return;
        clearPost(parent->leftChild);
        clearPost(parent->rightChild);
        delete parent;
    }

    // create a tree with item at root
    void createTree(const T &item)
    {
        root = new BSTNode<T>{item};
    }

    /* search tree for item, if item exists, return pointer to its node
       if item does not exist, return pointer to leaf node connection point */
    BSTNode<T> *searchNode(const T &item) const
    {
        BSTNode<T> *head{root};
        BSTNode<T> *trail{nullptr};

        while (head != nullptr)
        {
            // if item exists, return its node
            if (head->item == item)
                return head;
            // if item in node greater than search item, traverse left subtree
            else if (comparator(head->item, item))
            {
                trail = head;
                head = head->leftChild;
            }
            // if item in node lesser than search item, traverse right suntree
            else if (comparator(item, head->item))
            {
                trail = head;
                head = head->rightChild;
            }
            // return relevant last leaf node if item not found
        }
        return trail;
    }


    /* recurse through tree until item found -> copy smallest item in right subtree into item node
      -> create connection between item node and relevant subtree */
    BSTNode<T> *copyLete(BSTNode<T> *parent, const T &item)
    {
        if (parent == nullptr)
            return nullptr;
        else if (comparator(item, parent->item))
            parent->leftChild = copyLete(parent->leftChild, item);
        else if (comparator(item, parent->item))
            parent->rightChild = copyLete(parent->rightChild, item);
        else
        {
            if (parent->rightChild == nullptr && parent->leftChild == nullptr)
            {
                delete parent;
                parent = nullptr;
            }
            else if (parent->rightChild == nullptr)
            {
                BSTNode<T> *temp{parent};
                parent = parent->leftChild;
                delete temp;
            }
            else if (parent->leftChild == nullptr)
            {
                BSTNode<T> *temp{parent};
                parent = parent->rightChild;
                delete temp;
            }
            else
            {
                BSTNode<T> *temp{findMin(parent->rightChild)};
                parent->item = temp->item;
                parent->rightChild = copyLete(parent->rightChild, temp->item);
            }
        }
        return parent;
    }

    void enSequence(BSTNode<T> *parent)
    {
        if (parent == nullptr) return;
        enSequence(parent->leftChild);
        list.emplace_back(parent->item);
        enSequence(parent->rightChild);
    }

    // find the minimum value in a subtree
    BSTNode<T> *findMin(BSTNode<T> *parent) const
    {
        BSTNode<T> *head{parent};

        while (head->leftChild != nullptr)
            head = head->leftChild;

        return head;
    }
};

#endif