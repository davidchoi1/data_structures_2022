#include <iostream>

#ifndef PERSON_H
#define PERSON_H

struct Person
{

    //constructor initializes ID and Floor Destination
    Person(size_t, size_t);         
    
    size_t id;                                          // Person ID
    size_t assFloor;                                    // Assigned floor


};


#endif