#include <iostream>

enum class Status : unsigned long long
{
    WIN = 25,
    LOSS = 14,
    DRAW = 132
};

void printState(Status);

int main(int argc, char const *argv[])
{
    printState(Status::WIN);
    return 0;
}


void printState(Status s)
{
    switch (s)
    {
    case Status::WIN:
        std::cout << "You Won!!" << std::endl;
        break;
    case Status::LOSS:
        std::cout << "You Lost!!" << std::endl;
        break;
    case Status::DRAW:
        std::cout << "Draw!!" << std::endl;
        break;
    default:
        break;
    }
}