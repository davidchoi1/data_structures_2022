#include <vector>

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

template<typename T>
struct Vertex
{
    T item;                                                                         // !!data member called item which holds the payload!!
    
    std::vector<Vertex<T>*> nexts;                                                   // !!node pointer which is to point to the next node in!!

    Vertex(const T& item, Vertex<T>* next) : item{item}, nexts{next} { }             // !!node constructor taking in parameters (value, next pointer) and initializing to accepted parameters!!
    Vertex(const T& item) : Vertex<T>(item, nullptr) { }                            // !!second constructor for taking in just item value!!
};





#endif