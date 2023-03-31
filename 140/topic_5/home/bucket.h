// who: Dong Choi dchoi24
// what: The Bucket
// why: Bucket
// when: 10/30/22

// include guard
#ifndef bucket_H
#define bucket_H

// includes (only include these headers from the std library)
#include <stddef.h>
#include <stdexcept>

#define DEFAULT_SIZE 10
#define SCALING_FACTOR 2

/*  The bucket class */
class Bucket
{
	
public: 

	Bucket();
	
	Bucket(const size_t);
	
    size_t count();

    bool empty();

    void add(const double);

    double remove();

    bool remove(const double);

    void clear();

    size_t getFrequency(const double);

    bool contains(const double);

private:
	size_t itemCount;  
    double *items;
    size_t currentSize;

	void resize();
};

#endif 