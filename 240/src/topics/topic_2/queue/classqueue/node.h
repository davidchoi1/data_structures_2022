#include<iostream>

#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node                                                                         // !!struct because nodes are not encapsulated, everything is public!!
{
    T item;                                                                         // !!data member called item which holds the payload!!
    Node<T>* next;                                                                  // !!node pointer which is to point to the next node in!!

    Node(T item, Node<T>* next) : item{item}, next{next} { }                        // !!node constructor taking in parameters (value, next pointer) and initializing to accepted parameters!!
    Node(T item) : Node<T>(item, nullptr) { }                                       // !!second constructor for taking in just item value!!
};

#endif