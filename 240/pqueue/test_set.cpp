#include<iostream>
#include<unordered_set>

struct Student
{
    std::string name;
    uint64_t id;

    bool operator==(const Student& other) const
    {
        return name == other.name && id == other.id;            // student id is the indicator of equality
    }

    bool operator!=(const Student& other) const
    {
        return name != other.name && id != other.id;            // student id is the indicator of equality
    }

};

struct StudentHasher
{
    // what is operator doing here?? -> allowing StudentHasher to be used like a function
    int operator()(const Student& s) const
    {
        return (s.id >> 32 ^ s.id);                             // hashcode for student
    }
};

int main(int argc, char const *argv[])
{
    std::unordered_set<Student, StudentHasher> s;                                       // unordered set takes in student and a hasher
    Student s1{"fred",256458};                                                          // student created
    s.insert(s1);
    s.insert({"ted", 656458});
    s.insert({"ned", 756458});
    s.insert({"sam", 859458});

    if(s.find(s1) != s.end()) std::cout << "s contains the student\n";     // what does s.find() return?

    
    return 0;
}

// what is iterator with set
// how is hash function being used by passing in hasher class by template