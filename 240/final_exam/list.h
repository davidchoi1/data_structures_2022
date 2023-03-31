#include <string>
#include <stdexcept>
#include <iostream>

#ifndef LIST_H
#define LIST_H

template <typename T>
struct ListNode
{
    T item;
    ListNode<T> *next;
    ListNode<T> *prev;

    ListNode(const T &item, ListNode<T> *next, ListNode<T> *prev) : item{item}, next{next}, prev{prev} { }
    ListNode(const T &item) : ListNode<T>(item, nullptr, nullptr) { }
};

template <typename T>
class List
{
public:
    List() : head{nullptr}, prev{nullptr}, itemQty{0} {}

    void print()
    {
        ListNode<T> *itr{head};
        while (itr != nullptr)
        {
            std::cout << itr->item << "->";
            itr = itr->next;
        }
        std::cout << '\n';
    }

    size_t size()
    {
        return itemQty;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insert(T item, size_t idx)
    {
        if (isEmpty())                      // 1 - if list empty
            pushFront(item);
        else if (idx > itemQty)             // 2 - if index is out of range
            throw std::runtime_error("Error: Insert index out of range");
        else if (idx == itemQty)            // 3 - if index after very end
            pushBack(item);
        else if (idx == 0)                  // 4 - if front index
            pushFront(item);                
        else if (idx < itemQty)             // 5 - if internal node index
        {                           
            ListNode<T> *temp{getNodeAt(idx)};
            temp = new ListNode<T>(item, temp, temp->prev);
            temp->prev->next = temp;
            temp->next->prev = temp;
            ++itemQty;
        }
    }

    void remove(size_t idx)
    {
        if(isEmpty())                       // 1 - if empty
            throw std::runtime_error("Error: Remove on empty function");
        else if (idx >= itemQty)            // 2 - if the idx it out of range
            throw std::runtime_error("Error: Remove index out of range");
        else if (idx == 0)                  // 3 - if removing the first element
            popFront();
        else if (idx == itemQty - 1)        // 4 - if removing the last element
            popBack();
        else                                // 5 - if removing an internal element
        {
            ListNode<T> *temp{getNodeAt(idx)};
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            --itemQty;
        }
    }

    void pushFront(T item)
    {
        if (isEmpty())                      // 1 - if empty
            head = new ListNode<T>(item);
        else                                // 2 - if not empty
        {
            head = new ListNode<T>(item, head, nullptr);
            head->next->prev = head;
        }
        ++itemQty;
    }

    void pushBack(T item)
    {
        if (isEmpty())                      // 1 - if empty
            head = new ListNode<T>(item);
        else                                // 2 - if not empty
        {
            ListNode<T> *temp{lastElement()};
            temp->next = new ListNode<T>(item, nullptr, temp);
        }
        ++itemQty;
    }

    T popFront()
    {
        if (isEmpty())
            throw std::runtime_error("Error: Attempted popFront on empty list");

        ListNode<T> *temp{head};
        T val{head->item};
        head = head->next;
        delete temp;
        --itemQty;
        return val;
    }

    T popBack()
    {
        T val;

        if (isEmpty())              // 1 - if list empty
            throw std::runtime_error("Error: Attempted popBack on empty list");
        else if (itemQty == 1)      // 2 - if list has only one item
        {
            val = head->item;
            removeOnlyElement();
        }
        else                        // 3 - if list has several items
        {
            ListNode<T> *temp{lastElement()};
            val = head->item;
            temp->prev->next = nullptr;
            delete temp;
            --itemQty;
        }

        return val;
    }

    T peekFront()
    {
        if (isEmpty())
            throw std::runtime_error("Error: Attempted popBack on empty list");
        return head->item;
    }

    T peekBack()
    {
        if (isEmpty())
            throw std::runtime_error("Error: Attempted popBack on empty list");
        ListNode<T> *temp{lastElement()};
        return temp->item;
    }

    bool contains(T item)
    {
        ListNode<T> *temp{head};
        while (temp != nullptr)
        {
            if (temp->item == item)
                return true;
            temp = temp->next;
        }
        return false;
    }


private:
    ListNode<T> *head;
    ListNode<T> *prev;
    size_t itemQty;

    ListNode<T> *lastElement()
    {
        ListNode<T> *temp{head};
        while (temp->next != nullptr)
            temp = temp->next;
        return temp;
    }

    ListNode<T> *getNodeAt(size_t idx)
    {
        ListNode<T> *temp{head};

        for (size_t i{0}; i < idx; ++i)
            temp = temp->next;

        return temp;
    }

    void removeOnlyElement()
    {
        ListNode<T> *temp{head};
        delete temp;
        head = nullptr;
        --itemQty;
    }
};

#endif