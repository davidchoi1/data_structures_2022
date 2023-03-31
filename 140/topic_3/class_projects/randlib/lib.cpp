#include <cstdlib>
#include <ctime>
#include <stdexcept>

#include "lib.h"

int randRange(int start, int end)
{
    if(end > RAND_MAX) throw std::range_error("ERROR: End of random range is out of range.");

    return (rand() % (end - start + 1)) + start;                                                            // 
}

bool probability(float prob)
{
    return static_cast<float>(randRange(1, 100)) < prob;
}