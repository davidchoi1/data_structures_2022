#include "Astar.h"


int main(int argc, char const *argv[])
{
    std::array<char, BOARD_SIZE> board{'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    std::array<char, BOARD_SIZE> board2{'1', '3', '0', '2', '8', '4', '6', '5', '7'};
    State state(board);
    State state2(board2);
    Problem problem(state2);
    Heuristic heuristic;

    std::vector<State *> transVector;

    transVector = problem.stateTransitions(state2);

    Astar astar(problem, heuristic);
    astar.Asearch();
    
    astar.print();

    return 0;
}