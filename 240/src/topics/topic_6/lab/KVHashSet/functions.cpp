#include "functions.h"



int randRange2(int start, int end)
{
    return rand() % (end - start + 1) + start;
}