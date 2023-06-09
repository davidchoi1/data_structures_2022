#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstddef>

#ifndef COMMON_H
#define COMMON_H



#define FLOOR_QTY 50
#define NEW_PERSON_PROBABILITY 0.035
#define EXIT_PROBABILITY 0.015
#define LOBBY 0
#define TOP_FLOOR FLOOR_QTY - 1

bool isProbable(double p)
{
    int det = rand() % 1000;
    return (det <= static_cast<int>(p * 1000));
}

size_t randRange(size_t start, size_t end)
{
    return rand() % (end - start + 1) + start;
}

#endif