#include<stdexcept>

#include"bag.h"
#include"C:\Users\My Razer\Workspace\240\src\topics\node.h"

#ifndef LINKED_BAG_H
#define LINKED_BAG_H


template<typename T>
class LinkedBag : public Bag<T>
{
public:
    LinkedBag() : head{nullptr} { }                                                                                     // !!constructor for class LinkedBag which initalizes head pointer to null!!

    bool add(T item)                                                                                                    
    {
        head = new Node<T>(item, head);                                                                                 // !!set head pointer equal to new node pointer with item and previous head (adding to front of linked list!!
        ++this->count;                                                                                                  // !!increase the count by 1!!

        return true;                                                                     
    }

    bool remove(T item) 
    {
        Node<T>* it{findNode(item)};                                                                                    // !!declare iterator node pointer which points to the node of requested item!!
        Node<T>* temp{head};                                                                                            // !!store head node in temp pointer for deletion!!

        if(it != nullptr)                                                                                               // !!if it does not equal nullptr (if it's not at the end of linked list)!!
        {
            it->item = head->item;                                                                                      // !!place payload inside head into item memloc!! 
            head = head->next;                                                                                          // !!move head pointer to next node!!

            delete temp;                                                                                                // !!delete that old head node!!
            --this->count;                                                                                              // !!lower the count by one!!

            return true;                                                                                                // !!breakout!!
        }

        return false;                                                                                                   // !!otherwise, return false!!
    }

    bool contains(T item)
    {
        Node<T>* it{head};                                                                                            // !!create pointer of Node type T called temp!!
        while (it != nullptr)                                                                                         // !!while temp node pointer does not equal to item...!!
        {
            if(it->item == item) return true;                                                                         // ??if the temp pointer pointed item equals item requested, return true??

            it = it->next;                                                                                              // ??set temp pointer equal to temp next pointer??what does this accomplish??
        }                                                                                                               // ??why aren't we deleted temp here??

        return false;                                                                                                   // !!otherwise return false (doesn't contain)!!
    }

    size_t size()
    {
        return this->count;                                                                                             // !!return the count(size)!!
    }

    T grab()
    {
        if(this->count == 0)
            throw std::runtime_error("Grab on empty bag!");

        return head->item;
    }

private:
    Node<T>* head;                                                                                          // !!pointer to a node called head!!

    Node<T>* findNode(T item)                                                                               // ??why pointer helper function(returns a pointer)?? !!function to find the node of requested item!!
    {
        Node<T>* it{head};                                                                                  // ??declare node pointer called 'it' initialized to head node pointer??
        while(it != nullptr)                                                                                // !!while 'it' node does not equal null!!
        {
            if(it->item == item)                                                                            // !!if it node pointer of requested item equals requested item!!
                return it;                                                                                  // !!return it!!

            it = it->next;                                                                              // ??what is it node pointer being overwritten as?? the next node?? 
        }

        return nullptr;                                                                                     // !!otherwise, return the end of linked list!!
    }
};

#endif