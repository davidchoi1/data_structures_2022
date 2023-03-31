#include <iostream>

void swap(int &a, int &b

int main(int argc, char const *argv[])
{
    int x{10};
    int y{20};

    swap(x, y);
    std::cout << x << " " << y << std::endl;

    return 0;
}

void swap(int &a, int &b)
{
    int temp{a};
    a = b;
    b = temp;
}
