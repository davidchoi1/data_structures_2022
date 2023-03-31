#include<iostream>

int main(int argc, char const *argv[])
{
    for(size_t i{0}, l{0}, r{1}, t; i < 20; ++i, t = r, r += l, l = t)
        std::cout << l << " ";

    std::cout << std::endl;

    return 0;
}
