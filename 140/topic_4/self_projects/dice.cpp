#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>

#define POSSIBLE 11
#define TEST_COUNT 600'000

void printResult(std::array<int,POSSIBLE>&);

size_t diceAddVal();
size_t randRange(size_t, size_t);
double possibility(size_t);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    
    std::array<int, POSSIBLE> totalArray{0};
    

    for (size_t i{0}; i < TEST_COUNT; ++i)
        ++totalArray.at(diceAddVal());               

    printResult(totalArray);                                 

    return 0;
 
}


size_t diceAddVal()                                             
{
    return (randRange(0, 5) + randRange(0, 5));                    
}

size_t randRange(size_t start, size_t end)
{   
    return (rand() % (end - start + 1)) + start;
}

void printResult(std::array<int, POSSIBLE>& array)
{
    std::cout << std::setprecision(3) << std::fixed;                                                      

    std::cout << std::left << std::setw(6) << "Sum"
              << std::right << std::setw(9) << "Total"
              << "    " << "Expected" << "    " << "Actual\n"; 

    for (size_t i{0}; i < POSSIBLE; ++i)
    {
    std::cout << std::left << std::setw(10) << i + 2 << std::left 
              << std::setw(9) << array.at(i)<< possibility(i) / 36 * 100
              << "%" << std::right << std::setw(11) << static_cast<double>(array.at(i)) / 
              TEST_COUNT * 100 << "%" << std:: endl;
    }    
}

double possibility(size_t it)
{
    switch (it)
    {
    case 0: case 10:
        return 1;
    case 1: case 9:
        return 2;
    case 2: case 8:
        return 3;
    case 3: case 7:
        return 4;
    case 4: case 6:
        return 5;
    case 5:
        return 6;    
    }
}