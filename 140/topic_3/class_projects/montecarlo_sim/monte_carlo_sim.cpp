#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "monte_carlo_sim.h"

#define TEST_COUNT 100'000'000

int main(int argc, char const *argv[])
{

    srand(time(NULL));                                      // seed with random value

    size_t faces[FACE_COUNT]{ };                            // holds number of occurences of a particular number

    for (size_t i{0}; i < TEST_COUNT; ++i)
    {
        ++faces[randRange(0,FACE_COUNT - 1)];               // populate faces array with rand # between 0 and 5 (1-6)
    }

    printSimResult(faces);                                  // call print function

    return 0;
}


size_t randRange(size_t start, size_t end)
{   
    return (rand() % (end - start + 1)) + start;            // return random value with start and end inclusive
}

void printSimResult(size_t array[])
{
    std::cout << std::setprecision(2) << std::fixed;                                                        // stickies

    std::cout << std::left << std::setw(6) << "Face"
              << std::right << std::setw(16) << "\% of Ocurrences\n";                                       // print header

    for (size_t i{0}; i < FACE_COUNT; ++i)
    {
        std::cout << std::left << std::setw(6) << i + 1 << std::right 
                  << std::setw(16) << static_cast<double>(array[i]) / TEST_COUNT * 100 << std::endl;
    }
    
}
