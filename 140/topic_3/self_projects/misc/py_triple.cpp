#include <iostream>

int main(int argc, char const *argv[])
{
    for(int a{1}; a < 499; ++a)
        for(int b{a+1}; b < 500; ++b)
            for(int c{b+1}; c <= 500; ++c)
                if(c*c == a*a + b*b)
                    std::cout << a << " " << b << " " << c << std::endl;
    
    return 0;
}
