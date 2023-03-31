

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

T& operator[](size_t subscript)
{
    if(subscript >= itemQty) throw ListError("subscript out of bounds");
    Node<T>* it{head};

    for (size_t i{0}; i <= subscript; ++i)
        it = it->next;
    
    return (it->item);
    
}

const T& operator[](size_t subscript) const
{
    if(subscript >= itemQty) throw ListError("subscript out of bounds");
    Node<T>* it{head};

    for (size_t i{0}; i <= subscript; ++i)
        it = it->next;
    
    return (it->item);
}

#endif