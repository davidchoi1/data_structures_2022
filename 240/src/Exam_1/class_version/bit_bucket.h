#include <cstddef>
#include <stdexcept>
#ifndef BIT_BUCKET_H
#define BIT_BUCKET_H

template<size_t S>                                  // Bitbucket takes in size_t IN BITS
class BitBucket
{
public:
    void set(size_t pos)
    {
        if(pos >= S) throw std::range_error("Index out of range");

        size_t bytePos{pos >> 3};                           // find byte position of accepted parameter by dividing size IN BITS by 8
        size_t bitPos{pos - (bytePos << 3)};                // find bit position within the found byte position

        bucket[bytePos] |= masks[bitPos];
    }
    void unset(size_t pos)
    {
        if(pos >= S) throw std::range_error("Index out of range");

        size_t bytePos{pos >> 3};                           // find byte position of accepted parameter by dividing size IN BITS by 8
        size_t bitPos{pos - (bytePos << 3)};                // find bit position within the found byte position

        bucket[bytePos] &= masks[bitPos];                  // mask the found byte position of array with negation of accepted paramter bit position
    }
    bool at(size_t pos)
    {
        if(pos >= S) throw std::range_error("Index out of range");

        size_t bytePos{pos >> 3};                           // find byte position of accepted parameter by dividing size IN BITS by 8
        size_t bitPos{pos - (bytePos << 3)};                // find bit position within the found byte position
        
        return masks[bitPos] & bucket[bytePos];             // mask the found byte position of array with accepted paramter bit position
    }
    
    
    void clear()
    {
        size_t size{(S >> 3) + 1};                          // set up size IN BYTES to be used in for loop

        for (size_t i = 0; i < size; i++)                   // from i = 0 to size IN BYTES, set every element of array equal to 0
        {
            bucket[i] = 0;
        }
    }


private:
    unsigned char bucket[(S >> 3) + 1] { };                    // character array which translates size IN BITS (S) to size IN BYTES

    const unsigned char masks[8] 
    {
        0b00000001,
        0b00000010,
        0b00000100,
        0b00001000,
        0b00010000,
        0b00100000,
        0b01000000,
        0b10000000
    };
};

#endif  