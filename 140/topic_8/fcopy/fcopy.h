#include <fstream>

#ifndef FCOPY_H
#define FCOPY_H

struct InputFileOpeningError : public std::runtime_error
{
    InputFileOpeningError() : std::runtime_error("Error in open file!") {}
    InputFileOpeningError(const char *msg) : std::runtime_error(msg) {}
};

struct OutputFileOpeningError : public std::runtime_error
{
    OutputFileOpeningError() : std::runtime_error("Error in dest file!") {}
    OutputFileOpeningError(const char *msg) : std::runtime_error(msg) {}
};

struct FCopy
{
    void operator()(const std::string &, const std::string &);
};

#endif