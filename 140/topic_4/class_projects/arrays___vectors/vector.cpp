#include <iostream>
#include <vector>

void PrintVector(const std::vector<double>& vect)
{
    for (const double& d : vect)                                       
        std::cout << d << ' ';                                          
    std::cout << std::endl;
}

int main(int argc, char const *argv[])
{
    // vectors allow for dynamic resizing
    // vector type double, size 50
    std::vector<double> d(50);

    // initialize every element to its index
    for (size_t i{0}; i < d.size(); i++)
        d.at(i) = static_cast<double>(i);                                             

    // add 3.145 to end of vector
    d.push_back(3.1415);                                                            

    // print every vector
    PrintVector(d);
    return 0;
}
