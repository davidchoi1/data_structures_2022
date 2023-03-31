#include <string>
#include "name.h"
#ifndef STUDENT_CLASS_H
#define STUDENT_CLASS_H

class Student
{
    friend std::ostream& operator<<(std::ostream&, const Student&);
public:

    Student(const Name&, size_t);
    Student(const Student&);
    ~Student();

    const Name& getName();
    size_t get_ID();

    bool operator==(const Student&);
    bool operator!=(const Student&);

    static size_t getInstanceCount();
    

private:
    Name name;
    size_t student_ID;
    static size_t instanceCount;
};


#endif