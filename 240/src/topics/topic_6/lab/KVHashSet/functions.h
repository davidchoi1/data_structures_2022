#include <iostream>
#include <cstdint>
#include <cmath>
#include <functional>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define DEFAULT_SIZE 157
#define SCALING_FACTOR 2
#define SCALE_WHEN .6

enum Status 
{
    OCCUPIED,
    EMPTY,
    AVAILABLE
};

// union u
// {
//     double d;
//     uint64_t i;
// };

// int h1(int k)
// {
//     return k;                                                           // return int
// }

// int h1(uint64_t k)
// {
//     return static_cast<int>((k >> 32 ) + k);                            // turn 64 bit into 32 bit integer
// }

// int h1(double k)
// {
//     uint64_t* ki{reinterpret_cast<uint64_t*>(&k)};
//     return h1(*ki);
// }

// int h1(const std::string& k)
// {
//     int hash{0};
//     const int factor{31};

//     for (size_t i{0}; i < k.length(); ++i)
//     {
//         hash = factor * hash + k[i];
//     }

//     return hash;
// }

int randRange2(int start, int end);


#endif
