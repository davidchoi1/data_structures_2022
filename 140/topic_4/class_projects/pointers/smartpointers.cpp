#include <iostream>
#include <memory>

struct Person
{
    size_t ssn;
    std::string name;

    Person(size_t ssn, std::string name) : ssn{ssn}, name{name}
    {
        std::cout << "Created\n";
    }

    ~Person()
    {
        std::cout << "Deleted\n";
    }

};

// Person* personfactory(size_t ssn, std::string name)
// {
//     Person* p{new Person};
//     p->ssn = ssn;
//     p->name = name;
//     return p;
// }

int main(int argc, char const *argv[])
{
    // int* heapBound{new int{25}};                                                            // create value 25 in heap and return address to it
    // int b{*heapBound};                                                                      // b has access to value 25 and can change it permanently

    // Person* p{personfactory(624806994, "David")};
    // std::cout << p->ssn << " - " << p->name << std::endl;

    // delete p;
    // delete heapBound;

    {                                                                                                               // only within scope, unique pointer is destroyed after leaving its scope
        std::unique_ptr<Person> person = std::make_unique<Person>(624806994, "David");
        std::cout << person->ssn << " - " << person->name << std::endl;
    }

    {
        std::shared_ptr<Person> lucy = std::make_shared<Person>(624806994, "Lucy");
        std::cout << lucy->ssn << " - " << lucy->name << std::endl;
    }


    return 0;
}
