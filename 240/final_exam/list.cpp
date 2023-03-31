#include "list.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    List<int> list;


    for (size_t i{0}; i < 15; i++)
        list.insert(i, i);


    list.print();

    return 0;
}
