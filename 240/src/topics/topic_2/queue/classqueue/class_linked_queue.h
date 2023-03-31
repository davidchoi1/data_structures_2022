#include<stdexcept>

#include "class_queue.h"
#include "node.h"

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template<typename T>
class LinkedQueue : public Queue<T>
{
public:
    LinkedQueue() : frontptr{nullptr}, backptr{nullptr} { }                                          // constructor to create pointers of linked list

    void enqueue(T item)
    {
        (empty() ? backptr : backptr->next) = new Node<T>(item);                                  // if queue is empty, set backptr pointer equal to the node with the item, if not, set node after backptr equal to a new node with the item

        if(empty())
            frontptr = backptr;                                                                   // if its empty, frontptr and backptr pointers are in same spot
        else
            backptr = backptr->next;                                                              // point backptr pointer at the next node
    } 

    T dequeue()
    { 
        Node<T>* temp{frontptr};                                                               // intialize node pointer temp pointing at frontptr
        T rtnItem;                                                                          // declare variable which will hold the value to return     

        if(empty()) throw std::runtime_error("Dequeue on empty Queue");                      // error for empty

        rtnItem = frontptr->item;                                                              // put item in frontptr node into variable
        frontptr = frontptr->next;                                                                 // point frontptr pointer to next node
        delete temp;                                                                        // delete dat frontptr node 

        if(empty()) backptr = nullptr;                                                         // if its empty, set backptr equal to null

        return rtnItem;                                                                     // return the damn thing
    }                  

    T front()
    {
        if(empty()) throw std::runtime_error("frontptr on empty Queue");                        // error for empty

        return frontptr->item;                                                                 // return frontptr item
    }  

    bool empty()
    {
        return frontptr == nullptr;                                                            // returns the evaluation of the statement (true or false)
    }
    
    void clear()
    {
        Node<T>* temp{frontptr};                                                                // new node pointing to frontptr

        while(frontptr != nullptr)                                                             // while frontptr is not equal to null...
        {
            frontptr = frontptr->next;                                                            // set frontptr pointer equal to the next node
            delete temp;                                                                    // delete that frontptr node
            temp = frontptr;                                                                   // point your temp node at the NEW frontptr                                                    
        }

        backptr = nullptr;                                                                     // when everything is empty, set backptr equal to the null pointer
    }

private:
    Node<T>* frontptr;                                                                         // frontptr node pointer
    Node<T>* backptr;                                                                          // backptr node pointer
};

#endif