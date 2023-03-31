#include <stdexcept>
#ifndef OPENING_ERROR_H
#define OPENING_ERROR_H


struct InputFileOpeningError : public std::runtime_error
{
    InputFileOpeningError() : std::runtime_error("There was a test #2 excepton") {}
    InputFileOpeningError(const char *msg) : std::runtime_error(msg) {}
};


struct OutputFileOpeningError : public std::runtime_error
{
    OutputFileOpeningError() : std::runtime_error("There was a test #2 excepton") {}
    OutputFileOpeningError(const char *msg) : std::runtime_error(msg) {}
};

struct InvalidArgError : public std::invalid_argument
{
    InvalidArgError() : std::invalid_argument("Stuff Error") { }
};
#endif