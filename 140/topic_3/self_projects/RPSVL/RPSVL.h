#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#ifndef RPSVL_H
#define RPSVL_H

enum Status
{
    WIN,
    LOSS,
    DRAW
};

class RPSVL
{
public:
    void printWRules()
    {
        std::cout << "Welcome to Rock Paper Scissors Vader Luke\n"
              << "Rules: \n"
              << "\tScissors cuts paper.\n"
              << "\tPaper covers rock.\n"
              << "\tRock bashes Vader.\n"
              << "\tVader throws Luke.\n"
              << "\tLuke bends scissors.\n"
              << "\tScissors stabs Vader.\n"
              << "\tVader burns paper.\n"
              << "\tPaper banishes Luke.\n"
              << "\tLuke crushes rock.\n"
              << "\tRock breaks scissors.\n";
    }                                 


    void optionMenu()
    {
        std::cout << "Option Menu: \n"
              << "\t   (R)ock.\n"
              << "\t   (P)aper.\n"
              << "\t   (S)cissor.\n"
              << "\t   (V)ader.\n"
              << "\t   (L)uke.\n";
    }

    bool playOption()
    {
        char answer;
        std::cout << "Would you like to play? (y/n): " << std::endl;
    
        while(true)
        {
            std::cin >> answer;
            answer = tolower(answer);

            if(answer == 'y') return true;
            if(answer == 'n') return false;
    
            std::cout << "Wrong input, please enter y for yes, or n for no: ";
        }
    }

    bool playOption2()
    {
        char answer;
        std::cout << "Would you like to play again? (y/n): " << std::endl;
    
        while(true)
        {
            std::cin >> answer;
            answer = tolower(answer);

            if(answer == 'y') return true;
            if(answer == 'n') return false;
    
            std::cout << "Wrong input, please enter y for yes, or n for no: ";
        }
    }

    int userInput()
    {
        char c;
        int val{0};

        while(true)
        {
            std::cout << "Enter the letter of your choice: ";
            std::cin >> c;
            c = tolower(c);


            if(c == 'r') {
                val = 1;
                break;
            } else if(c == 'p') {
                val = 2;
                break;
            } else if(c == 's') {
                val = 3;
                break;
            } else if(c == 'v') {
                val = 4;
                break;
            } else if(c == 'l') {
                val = 5;
                break;
            }
    
            std::cout << "Wrong letter choice, try r, p, s, v, or l.\n";
       }
       
        return val;
    }

    int getRandomChoice()
    {
        return (rand() % (5)) + 1;                                                            // 
    }


    void round(int c, int u)
    {
        switch (c)
        {
        case 1:
            rock(u);
            break;
        case 2:
            paper(u);
            break;
        case 3:
            scissor(u);
            break;
        case 4:
            Vader(u);
            break;
        case 5:
            Luke(u);
            break;        
        }
    }


private:

    void printState(Status s)
    {
        switch (s)
        {
        case WIN:
            std::cout << "You Won!!" << std::endl;
            break;
        case LOSS:
            std::cout << "You Lost!!" << std::endl;
            break;
        case DRAW:
            std::cout << "Draw!!" << std::endl;
            break;
        default:
            break;
        }
    }


    void rock(int u)
    {
        std::cout << "Opponent chose rock.\n"
                    << "Paper covers rock.\n"
                    << "Rock bashes Vader.\n"
                    << "Luke crushes rock.\n"
                    << "Rock break scissor.\n";
        
        switch (u)
        {
        case 1:
            printState(DRAW);
            break;
        case 2:
            printState(WIN);
            break;
        case 3:
            printState(LOSS);
            break;
        case 4:
            printState(LOSS);
            break;
        case 5:
            printState(WIN);
            break;      
        }
    }

    void paper(int u)
    {
        std::cout << "Opponent chose paper.\n"
                    << "Scissors cuts paper.\n"
                    << "Paper covers rock.\n"
                    << "Vader burns paper.\n"
                    << "Paper banishes Luke.\n";

        switch (u)
        {
        case 1:
            printState(LOSS);
            break;
        case 2:
            printState(DRAW);
            break;
        case 3:
            printState(WIN);
            break;
        case 4:
           printState(WIN);
            break;
        case 5:
            printState(LOSS);
            break;      
        }
    }

    void scissor(int u)
    {
        std::cout << "Opponent chose scissor.\n"
                    << "Scissors cuts paper.\n"
                    << "Luke bends scissors.\n"
                    << "Scissors stabs Vader.\n"
                    << "Rock break scissor.\n";

        switch (u)
        {
        case 1:
            printState(WIN);
            break;
        case 2:
            printState(LOSS);
            break;
        case 3:
            printState(DRAW);
            break;
        case 4:
            printState(LOSS);
            break;
        case 5:
            printState(WIN);
            break;      
        }
    }

    void Vader(int u)
    {
        std::cout << "Opponent chose Vader.\n"
                    << "Rock bashes Vader.\n"
                    << "Vader throws Luke.\n"
                    << "Scissors stabs Vader.\n"
                    << "Vader burns paper.\n";

        switch (u)
        {
        case 1:
            printState(WIN);
            break;
        case 2:
            printState(LOSS);
            break;
        case 3:
            printState(WIN);
            break;
        case 4:
            printState(DRAW);
            break;
        case 5:
            printState(LOSS);
            break;      
        }
    }

    void Luke(int u)
    {
        std::cout << "Opponent chose Luke.\n"
                    << "Vader throws Luke.\n"
                    << "Luke bends scissors.\n"
                    << "Paper banishes Luke.\n"
                    << "Luke crushes rock.\n";

        switch (u)
        {
        case 1:
            printState(LOSS);
            break;
        case 2:
            printState(WIN);
            break;
        case 3:
            printState(LOSS);
            break;
        case 4:
            printState(WIN);
            break;
        case 5:
            printState(DRAW);
            break;      
        }
    }



};


#endif