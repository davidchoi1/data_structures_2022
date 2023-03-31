#include<stdexcept>

#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node                                                                         // !!struct because nodes are not encapsulated, everything is public!!
{
    T item;                                                                         // !!data member called item which holds the payload!!
    Node<T>* next;                                                                  // !!node pointer which is to point to the next node in!!

    Node(const T& item, Node<T>* next) : item{item}, next{next} { }                        // !!node constructor taking in parameters (value, next pointer) and initializing to accepted parameters!!
    Node(const T& item) : Node<T>(item, nullptr) { }                                       // !!second constructor for taking in just item value!!
};

template<typename T>
class LinkedList
{
public:
    LinkedList() : head{nullptr} { }

    void add(const T& item) { head = new Node<T>{item, head}; }

    bool contains(const T& item)
    {
        Node<T>* ptr{head};                                                              // seperate pointer pointing to head to be used for iteration
        while(ptr != nullptr)
        {
            if(ptr->item == item) return true;
            ptr = ptr->next;
        }

        return false;
    }

    T erase(const T& item)
    {
        Node<T>* lead{head};
        Node<T>* prev{};

        while (lead != nullptr)
        {
            if(lead->item == item) return deleteNode(prev, lead);

            prev = lead;
            lead = lead->next;
        }

        throw std::runtime_error("Item not found");
        
    }



private:
    Node<T>* head;

    T deleteNode(Node<T>* prev, node<T>* eraseNode)
    {
        T rtnItem{eraseNode->item};

        if(prev == nullptr)                                     // 
            head = eraseNode->next;
        else
        {
            prev->next = eraseNode->next
        }
        delete eraseNode;
        return rtnItem;
    }
};

#endif