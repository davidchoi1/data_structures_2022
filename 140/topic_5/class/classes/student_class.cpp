#include "student_class.h"
#include "name.h"


Student::Student(const Name& name, size_t student_ID) : name{name}, student_ID{student_ID}
{
    ++instanceCount;
}



Student::Student(const Student& other)                                                                              
{
    name = other.name;
    student_ID = other.student_ID;
    ++instanceCount;
}

Student::~Student() { --instanceCount; }

const Name& Student::getName() { return name; }

size_t Student::get_ID() { return student_ID; }




bool Student::operator==(const Student& other) { return student_ID == other.student_ID; }

bool Student::operator!=(const Student& other) { return !(student_ID == other.student_ID); }

std::ostream& operator<<(std::ostream& out, const Student& s)
{
    return out << s.student_ID << " - " << s.name;
}

static size_t Student::getInstanceCount() { return Student::instanceCount; }

size_t Student::instanceCount = 0;