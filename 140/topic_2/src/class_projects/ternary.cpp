#include<iostream>

int main(int argc, char const *argv[])
{
    int i{10};
    int j{100};
    int k;
    bool test{false};

    ((test) ? i : j) += 1000;                                                                // if test is true, increment i by 1000, if test is false, increment j by 1000

    std::cout << "i = " << i << " j = " << j << std::endl;
    
    std::cout << (i > j ? i : j) << std::endl;

    std::cout << k << std::endl;

    // if(test) i  = 50;
    // else i = 10;

    // i = (test) ? 50 : 10;                                                               // this is the same as the above decision structure except better performing

    return 0;
}
