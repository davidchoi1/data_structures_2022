// who:  Prof.A
// what: BitBucket Interface
// why:  Lab Exam 1
// when: 2022-09-20

/* DO NOT CHANGE THIS CODE */

#include <cstddef>

#ifndef BIT_BUCKET_H
#define BIT_BUCKET_H

#define MASK 1

class BitBucket
{
public:
    // Constructor: creates an array of the requested size
    // size_t size: Size in bits
    BitBucket(size_t size);

    // Set a bit at the requested position
    // Throws std::range_error if pos >= size
    void set(size_t pos);

    // Unset a bit at the requested position
    // Throws std::range_error if pos >= size
    void unset(size_t pos);

    // Retrieve a bit from the bucket "at" the requested position
    // Size_t pos: the position at which to retrieve the bit
    // Returns the boolean value of the bit at a specific position
    // Throws std::range_error if pos >= size
    bool at(size_t pos);
    
    // resets all bits to zero
    void clear();

private:
    unsigned char* bucket;  // array of bytes to use for the bucket
    size_t size;            // Size of the bucket in bits
};

#endif  /* BIT_BUCKET_H */

/* DO NOT CHANGE THIS CODE */