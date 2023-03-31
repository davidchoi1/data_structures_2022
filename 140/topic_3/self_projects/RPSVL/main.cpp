#include "RPSVL.h"


int main(int argc, char const *argv[])
{
    srand(time(NULL));                                          // seed rand

    RPSVL game;                                                 // create game object

    game.printWRules();                                         // print the rules of the game

    while(true)                                                 // keep playing until user chooses to stop
    {
    
        bool playorno = game.playOption();                          // get user input for willingness to play

        if(playorno == false)                                       // break out if player don't wannSSSa play
        {
            std::cout << "Thanks for playing!";
            break;
        }

        while(true)
        {
            game.optionMenu();                                          // print option menu

            int u = game.userInput();                                   // get users choice
            int c = game.getRandomChoice();                             // get computer choice

            game.round(c, u);

            playorno = game.playOption2();
            if(playorno == false)                                       // break out if player don't wannSSSa play
            {
                std::cout << "Thanks for playing!";
                break;
            }   
        }

        break;
    }   
    

    return 0;
}


