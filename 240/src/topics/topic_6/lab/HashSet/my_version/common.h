#include <iostream>
#include <cstdint>
#include <cmath>
#include <functional>

#ifndef COMMON_H
#define COMMON_H

#define DEFAULT_SIZE 157
#define SCALING_FACTOR 2
#define SCALE_WHEN .6
#define PROBE_MAX 27

enum status 
{
    OCCUPIED,
    EMPTY,
    AVAILABLE
};

template<typename T>
struct Common
{
    Common() = default;
    Common(T key, int status) : key{key}, status{status} { }
    Common(T key) : key{key}, status{OCCUPIED} { }

    int status;
    T key;

};



#endif