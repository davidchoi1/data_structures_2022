#include <stdexcept>

#ifndef ACCOUNT_ERROR_H
#define ACCOUNT_ERROR_H

struct AccountError : public std::runtime_error
{
    AccountError(const char* msg) : std::runtime_error{msg} { }
    
    AccountError() : std::runtime_error{"ERROR: Account operation error!"} { }

};

#endif