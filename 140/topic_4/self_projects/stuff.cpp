#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
    std::array<std::array<int,5>, 6> a;
    a[0][1] = 8;
    std::cout << a[0][1] << std::endl;
    return 0;
}
