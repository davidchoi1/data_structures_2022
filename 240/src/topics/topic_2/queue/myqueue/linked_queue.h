#include<stdexcept>

#include"queue.h"
#include"C:\Users\My Razer\Workspace\240\src\topics\node.h"

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

template<typename T>
class LinkedQueue : public Queue<T>
{
public:
    LinkedQueue() : head{nullptr} { }                                               // pointer head initialized to point at null

    bool enqueue(T item)
    {
        head = new Node<T>(item, head);                                             // place accepted item at head and make old head next
    }

    T dequeue()
    {
        T val = front();                                                            // let variable val hold front value
        
        if(head->next == nullptr)                                                   // if null after head
            delete head;                                                            // delete head node
            
        Node<T>* it{head};                                                          // declare iterator
            
        while(it->next->next != nullptr)                                            // while 2 nodes down isn't null..
            it = it->next;                                                          // set iterator equal to next node
        
        delete it->next;                                                            // once 2 nodes down is null, delete next node(last node)
        it->next = nullptr;                                                         // set last node equal to null
                                                        

       return val;                                                                  // return front node value
    }
    
    T front()
    {
        if(head == nullptr)                                                         // if head equal to null...
            throw std::runtime_error("Queue's empty bruh");                         // throw exception

        if(head->next == nullptr)                                                   // if next node is null...
            return head->item;                                                      // return head payload
            
        Node<T>* it{head};                                                          // declare iterator
            
        while(it->next->next != nullptr)                                            // while 2 nodes down isn't null...
            it = it->next;                                                          // set iterator equal to next node

        return it->next->item;                                                      // once 2 nodes down is null, return item at next node (front item)
    }
    
    bool empty()
    {
        return head == nullptr;                                                     // return true if head is pointing at null
    }

    void clear()
    {
        Node<T>* temp{};                                                            // declare temp node

        while(head != nullptr)                                                      // head head isn't null
        {
            temp = head;                                                            // store head node in temp
            head = head->next;                                                      // move one node over
            delete temp;                                                            // delete node in temp (previous head node)
        }
    }
private:
    Node<T>* head;                                                                  // node pointer head to keep track of head
    
};

#endif