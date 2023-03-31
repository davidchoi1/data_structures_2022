#include <stdexcept>

#ifndef LIST_ERROR_H
#define LIST_ERROR_H

struct ListError : public std::runtime_error
{
    ListError(const char* msg) : std::runtime_error{msg} { }
    
    ListError() : std::runtime_error{"ERROR: List operation error!"} { }



};

#endif