#include <iostream>
#include "errors.h"

void testException1()
{
    throw TestException("test exception 1");
}

void testException2()
{
    throw TestException2("test exception 2");
}

int main(int argc, char const *argv[])
{
 
        try
        {
        
            testException1();
            testException2();
        }
        catch (const TestException &a)
        {
            std::cerr << a.what() << '\n';

        }
        catch (const TestException &)
        {
            std::cerr << "caught testexcept 2" << '\n';
        }
        catch (const std::runtime_error &)
        {
            std::cerr << "stuff" << '\n';
        }


    return 0;
}







