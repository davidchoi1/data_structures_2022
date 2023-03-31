#include <iostream>
#include <array>
#include <fstream>

#define COLUMNS 4
#define ROWS 10
#define NUMSIZE 7

std::array<int, NUMSIZE> getInput();
std::ofstream lehInput();

int main(int argc, char const *argv[])
{
    int counter{0};
    int num{0};

    // holds opened output file
    std::ofstream oFile = lehInput();

    // each elemet of userInput holds the number to be used as an index in numLetters array
    std::array<int, 7> userInput = getInput();

    // each index corresponds with number and its subsequent letters
    std::array<std::array<char, COLUMNS>, ROWS> numLetters{
        {
            {},                     // 0
            {},                     // 1
            {'A', 'B', 'C'},        // 2
            {'D', 'E', 'F'},        // 3
            {'G', 'H', 'I'},        // 4
            {'J', 'K', 'L'},        // 5
            {'M', 'N', 'O'},        // 6
            {'P', 'Q', 'R', 'S'},   // 7
            {'T', 'U', 'V'},        // 8
            {'W', 'X', 'Y', 'Z'},   // 9
        }};

    // print to file
    for (size_t i{0}; i < (num = (userInput[0] == 7 || userInput[0] == 9) ? 4 : 3); ++i)
        for (size_t j{0}; j < (num = (userInput[1] == 7 || userInput[1] == 9) ? 4 : 3); ++j)
            for (size_t k{0}; k < (num = (userInput[2] == 7 || userInput[2] == 9) ? 4 : 3); ++k)
                for (size_t l{0}; l < (num = (userInput[3] == 7 || userInput[3] == 9) ? 4 : 3); ++l)
                    for (size_t m{0}; m < (num = (userInput[4] == 7 || userInput[4] == 9) ? 4 : 3); ++m)
                        for (size_t n{0}; n < (num = (userInput[5] == 7 || userInput[5] == 9) ? 4 : 3); ++n)
                            for (size_t o{0}; o < (num = (userInput[6] == 7 || userInput[6] == 9) ? 4 : 3); ++o)
                            {
                                if (counter == 8)
                                {
                                    counter = 0;
                                    oFile << "\n";
                                }
                                else
                                {
                                    oFile << numLetters[userInput.at(0)][i] << numLetters[userInput.at(1)][j] << numLetters[userInput.at(2)][k]
                                          << numLetters[userInput.at(3)][l] << numLetters[userInput.at(4)][m] << numLetters[userInput.at(5)][n]
                                          << numLetters[userInput.at(6)][o] << " ";
                                    ++counter;
                                }
                            }

    oFile.close();

    return 0;
}

std::ofstream lehInput()
{
    std::ofstream oFile;
    std::string stuff;
    std::cout << "Enter the output filepath: ";
    std::cin >> stuff;

    oFile.open(stuff);

    if (!oFile.is_open())
    {
        std::cout << "Error: File not available, please enter appropriate filepath." << std::endl;
        lehInput();
    }

    return oFile;
}

std::array<int, NUMSIZE> getInput()
{
    int counter{0};
    std::string input;
    std::array<int, NUMSIZE> returnPut;
    std::cout << "Enter a phone number (digits 2 through 9) in the form: xxx-xxxx: ";
    std::cin >> input;

    if (input.size() != 8)
    {
        std::cout << "Error: Length of input not appropriate, please try again" << std::endl;
        getInput();
    }

    for (auto i : input)
        if ((i < '2' || i > '9') && i != '-')
        {
            std::cout << "Error: You entered a character outside of 2 and 9, please enter numbers between 2 and 9: " << std::endl;
            getInput();
        }

    for (auto i : input)
    {
        if (i != '-')
        {
            returnPut.at(counter) = i - 48;
            ++counter;
        }
    }

    return returnPut;
}