#include <iostream>
#include <iomanip>
#include <array>
#include <ctime>

#define ROWS 6
#define COLUMNS 6
#define TEST_COUNT 600'000

size_t randRange(size_t, size_t);
void popCell(std::array<std::array<int, COLUMNS>, ROWS> &);
void one(std::array<std::array<int,COLUMNS>, ROWS>&);
void two(std::array<std::array<int,COLUMNS>, ROWS>&);
void three(std::array<std::array<int,COLUMNS>, ROWS>&);
void four(std::array<std::array<int,COLUMNS>, ROWS>&);
void five(std::array<std::array<int,COLUMNS>, ROWS>&);
void six(std::array<std::array<int,COLUMNS>, ROWS>&);
void printResult(sC&);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    std::array<std::array<int, COLUMNS>, ROWS> diceArray{0};

    for (size_t i{0}; i < TEST_COUNT; ++i)
        popCell(diceArray);

    printResult(diceArray);

    return 0;
}

size_t randRange(size_t start, size_t end)
{
    return (rand() % (end - start + 1)) + start;
}

void popCell(std::array<std::array<int, COLUMNS>, ROWS> &array)
{
    switch (randRange(0,5))
    {
    case 0:
        one(array);
        break;
    case 1 : 
        two(array);
        break;
    case 2:
        three(array);
        break;
    case 3:
        four(array);
        break;
    case 4:
        five(array);
        break;
    case 5:
        six(array);
        break;           
    }
}

void one(std::array<std::array<int,COLUMNS>, ROWS>& array)
{
    switch (randRange(0, 5))
    {
    case 0:
        ++array[0][0];
        break;
    case 1:
        ++array[0][1];
        break;
    case 2:
        ++array[0][2];
        break;
    case 3:
        ++array[0][3];
        break;
    case 4:
        ++array[0][4];
        break;
    case 5:
        ++array[0][5];
        break;
    }
}

void two(std::array<std::array<int,COLUMNS>, ROWS>& array)
{
    switch (randRange(0, 5))
    {
    case 0:
        ++array[1][0];
        break;
    case 1:
        ++array[1][1];
        break;
    case 2:
        ++array[1][2];
        break;
    case 3:
        ++array[1][3];
        break;
    case 4:
        ++array[1][4];
        break;
    case 5:
        ++array[1][5];
        break;
    }
}

void three(std::array<std::array<int,COLUMNS>, ROWS>& array)
{
    switch (randRange(0, 5))
    {
    case 0:
        ++array[2][0];
        break;
    case 1:
        ++array[2][1];
        break;
    case 2:
        ++array[2][2];
        break;
    case 3:
        ++array[2][3];
        break;
    case 4:
        ++array[2][4];
        break;
    case 5:
        ++array[2][5];
        break;
    }
}

void four(std::array<std::array<int,COLUMNS>, ROWS>& array)
{
    switch (randRange(0, 5))
    {
    case 0:
        ++array[3][0];
        break;
    case 1:
        ++array[3][1];
        break;
    case 2:
        ++array[3][2];
        break;
    case 3:
        ++array[3][3];
        break;
    case 4:
        ++array[3][4];
        break;
    case 5:
        ++array[3][5];
        break;
    }
}

void five(std::array<std::array<int,COLUMNS>, ROWS>& array)
{
    switch (randRange(0, 5))
    {
    case 0:
        ++array[4][0];
        break;
    case 1:
        ++array[4][1];
        break;
    case 2:
        ++array[4][2];
        break;
    case 3:
        ++array[4][3];
        break;
    case 4:
        ++array[4][4];
        break;
    case 5:
        ++array[4][5];
        break;
    }
}

void six(std::array<std::array<int,COLUMNS>, ROWS>& array)
{
    switch (randRange(0, 5))
    {
    case 0:
        ++array[5][0];
        break;
    case 1:
        ++array[5][1];
        break;
    case 2:
        ++array[5][2];
        break;
    case 3:
        ++array[5][3];
        break;
    case 4:
        ++array[5][4];
        break;
    case 5:
        ++array[5][5];
        break;
    }
}

void printResult(std::array<std::array<int, COLUMNS>, ROWS>& array)
{
    size_t j{0};                                                    
    std::cout << std::left << std::setw(3) << "#"
              << std::right << std::setw(5) << "1"
              << std::right << std::setw(8) << "2"
              << std::right << std::setw(8) << "3"
              << std::right << std::setw(8) << "4"
              << std::right << std::setw(8) << "5"
              << std::right << std::setw(8) << "6\n";;

    for (size_t i{0}; i < ROWS; ++i)
    {
        std::cout << std::left << std::setw(5) << i + 1 << array[i][j++] << "   " << array[i][j++] 
                  << "   " << array[i][j++] << "   " << array[i][j++] << "   " << array[i][j++] 
                  << "   " << array[i][j] << std::endl;
        j = 0;
    }   

}