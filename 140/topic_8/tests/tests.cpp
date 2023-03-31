#include <iostream>


class Parent
{
public: 
    virtual void say()
    {
        std::cout << "you're fat" << std::endl;
    }
};

class Child : public Parent
{
public:
    void say()
    {
        std::cout << "you're chubby" << std::endl;
    }

};

int main(int argc, char const *argv[])
{
    Child child;
    Parent parent;

    parent.say();
    child.say();
    return 0;
}
