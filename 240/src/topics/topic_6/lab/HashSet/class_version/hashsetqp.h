#include "hashset.h"
#ifndef HASHSETQP_H
#define HASHSETQP_H

template<typename T>
class HashsetQP : public Hashset<T>
{

private:
    int locateItem(const T& item)
    {
        int s = this->hashcode(item);

        for (size_t i = 0; i < PROBE_LIMIT; i++)
        {
            size_t it{ (s + i * i) % INIT_SIZE };

            if (this->store[it].status == EMPTY) return -1;

            if (this->store[it].status == OCCUPIED && this->store[it].item == item)
                return it;
        }

        return -1;
    }

    int locateAvailPos(const T&)
    {

    }


}


#endif