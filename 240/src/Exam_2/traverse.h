#include <iostream>

#ifndef TRAVERSE_H
#define TRAVERSE_H

#define ROOT 1

template<typename T>
class Traverse
{
public:
 
    Traverse(const T array[], size_t size) : store{new T[size + 1]}, itemQty{size}                          
    {
        for (size_t i{0}; i < size; ++i)
        {
            store[i + 1] = array[i];
        }       
    }

    void traverse()
    {
        postOrder(ROOT);
    }


private:
    size_t itemQty;                                                                                              
    T *store;    

    void process(size_t idx)
    {
        std::cout << store[idx] << std::endl;
    }

    void preOrder(size_t parentIdx)
    {
        size_t lchild{parentIdx << 1};
        size_t rchild{lchild + 1};

        if(parentIdx > itemQty) return;
        
        process(parentIdx);

        preOrder(lchild);
        preOrder(rchild);
    }

    void inOrder(size_t parentIdx)
    {
        size_t lchild{parentIdx << 1};
        size_t rchild{lchild + 1};

        if(parentIdx > itemQty) return;

        inOrder(lchild);
        process(parentIdx);
        inOrder(rchild);
    }

    void postOrder(size_t parentIdx)
    {
        size_t lchild{parentIdx << 1};
        size_t rchild{lchild + 1};

        if(parentIdx > itemQty) return;

        postOrder(lchild);
        postOrder(rchild);
        process(parentIdx);
    }
};


#endif