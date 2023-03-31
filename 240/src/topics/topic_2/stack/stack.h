#include <stdexcept>
#ifndef STACK_H                                             // ??header guard to avoid naming collision??
#define STACK_H



template<typename T>
struct Node                                                  
{
    T val;                                                  // !!type T declare variable called val!!what purpose??
    Node* next;                                             // !!create node pointer called next!!
    Node(T val, Node<T>* next) : val{val}, next{next} { }   // ??Define node as taking in val and node pointer next. Initialize val with value parameter and next with next parameter??
};


template<typename T>
class Stack                                                 
{
public:                                                     
    Stack() : head{nullptr} {};                             // !!constructor which initializes head pointer to null!!for what purpose??
    ~Stack() { clear(); }                                   // !!deconstructor which clears the stack??how does this happen??


    bool empty() 
    { 
        return head == nullptr;                             // !!boolean - if stack empty is true, return head pointer = null!!
    }                                                       


    void push(T val) 
    { 
        head = new Node<T>(val, head);                      // !!set head pointer equal to a new node with val on top of head??right??
    }     

    T peek()                                                
    {
        if(empty()) throw std:: runtime_error("Empty bruv");        // !!if stack is empty, throw error!!
        
        return head->val;                                           // !!otherwise, return the head pointer which points to val added!!right??
    }

    T pop()
    {
        if(empty()) throw std:: runtime_error("Empty bruv");        // !!if stack is empty, throw error!!

        // Node<T>* temp{head};                                // !!create a temporary node pointer which points to same memloc as head!!
        T val{head->val};                                   // ??declare value initialized to the value at head?? what is head->val doing??

        head = head->next;                                  // ??replace head pointer with pointer to next??
        // delete temp;                                        // ??when do we even use this??
        return val;                                         // ??return the value stored at 
    }

    void clear()
    {
        Node<T>* temp{};                                    // ??create temporary node pointer called temp which points to nothing??

        while(head != nullptr)                              // ??while the head pointer doesn't point to nothing??
        {
            temp = head;                                    // !!store head pointer in temp pointer!!
            head = head->next;                              // !!set head pointer equal to next next memloc!!
            delete temp;                                    // ??what??did we use this temp??
        }
    }

private:                                                   
    Node<T>* head;                                          // ??create pointer node called head??used to keep track of the head of the stack??


    // Node<T>* clear(Node<T>* n)                              // ??Node pointer function called clear which takes in Node pointer parameter called ??
    // {
    //     if(n == nullptr) return nullptr;                    // !!if requested node pointer is pointing at null, return null!!

    //     Node<T>* t {n->next};                               // ??Declare node pointer called t initialized to next value/memloc??

    //     delete n;                                           

    //     return clear(t);                                    // ??what??
    // }

};


#endif