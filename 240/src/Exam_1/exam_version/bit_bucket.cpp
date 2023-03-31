// who:  <your name>
// what: BitBucket Definition
// why:  Lab Exam 1
// when: 2022-09-20

#include <stdexcept>
#include "bit_bucket.h"

const size_t bitMask[]{1,2,4,8,16,32,64,128};                                                   //??array with each byte position turned on??                                                      

// Constructor: creates an array of the requested size                                          //??what should populate the array??when and where do I instantiate the population of the array??
// size_t size: Size in bits                                                                    //??how do I create the array in the test program??
BitBucket::BitBucket(size_t size, unsigned char* bucket) : size{size}, bucket{bucket} { }                 //??what should the size of the array be?? and why??

// Set a bit at the requested position
// Throws std::range_error if pos >= size
void BitBucket::set(size_t pos)
{
    
}

// Unset a bit at the requested position
// Throws std::range_error if pos >= size
void BitBucket::unset(size_t pos);

// Retrieve a bit from the bucket "at" the requested position
// Size_t pos: the position at which to retrieve the bit
// Returns the boolean value of the bit at a specific position
// Throws std::range_error if pos >= size
bool BitBucket::at(size_t pos);
    
// resets all bits to zero
void BitBucket::clear();

unsigned char* bucket;  // array of bytes to use for the bucket                             //??does this need to be here??
size_t size;            // Size of the bucket in bits
