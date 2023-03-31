#include<stdexcept>

#ifndef SKIPLIST_ERROR
#define SKIPLIST_ERROR

struct SkiplistError : public std::runtime_error
{
    SkiplistError() : std::runtime_error("Bad Skiplist operation") { }
    SkiplistError(const char* msg) : std::runtime_error(msg) { }
};

#endif /* SKIPLIST_ERROR */
