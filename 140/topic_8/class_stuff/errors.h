#include <stdexcept>


#ifndef ERRORS_H
#define ERRORS_H

struct TestException : public std::runtime_error
{
    TestException() : std::runtime_error("There was a test excepton") {}
    TestException(const char *msg) : std::runtime_error(msg) {}
};

struct TestException2 : public std::runtime_error
{
    TestException2() : std::runtime_error("There was a test #2 excepton") {}
    TestException2(const char *msg) : std::runtime_error(msg) {}
};

#endif