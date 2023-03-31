#include <array>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <queue>
#include <functional>
#include <unordered_set>

#ifndef STATE_PROB_HEUR_H
#define STATE_PROB_HEUR_H


#define BOARD_SIZE 9
#define MAX_VECT_SIZE 4
#define GOAL_HASH 1575145652

struct State
{
    State(const std::array<char, BOARD_SIZE> &board) : board{board}, hashCode{h1Array(board)} {}

    // state and hashcode representation
    std::array<char, BOARD_SIZE> board;
    const int hashCode;

    // hashcode function
    int h1Array(const std::array<char, BOARD_SIZE> &k)
    {
        int hash{0};
        const int factor{31};

        for (size_t i{0}; i < k.size(); ++i)
        {
            hash = factor * hash + k[i];
        }

        return hash;
    }

    // way to compare two states
    bool operator==(const State &other) const
    {
        for (size_t i = 0; i < board.size(); i++)
        {
            if (board.at(i) != other.board.at(i))
                return false;
        }
        return true;
    }
};


class Problem
{
public:
    Problem(State state) : initState{state} {}

    int stepCost()
    {
        return 1;
    }

    State initialState()
    {
        return initState;
    }

    std::vector<State*> stateTransitions(const State &begState)
    {
        // holds indices for swapping with '0'
        std::vector<int> transVector(MAX_VECT_SIZE);
        // holds all the possible states that sprout from given state
        std::vector<State*> transStates(MAX_VECT_SIZE);

        // iterate board to find position of '0'
        for (size_t i{0}; i < BOARD_SIZE; ++i)
        {
            if (begState.board.at(i) == '0')
            {
                // transVector holds indices to swap with 0
                transVector = actionVector(i);

                /* for each indices in transVector, generate and store all
                   possible potential states in transStates */
                for (size_t j{0}; j < transVector.size(); ++j)
                    transStates.at(j) = new State(swapStates(begState.board, i, transVector.at(j)));

                return transStates;
            }
        }
    }

    // change to same as the other thing
    bool goalTest(const State &state)
    {
        for (char i{'0'}; i < '9'; ++i)
            if (state.board[i - '0'] != i)
                return false;
        return true;
    }

    bool isValid(const State &state)
    {
        size_t counter{0};
        for (size_t i = 0; i < 8; i++)
            for (size_t j = i + 1; j < 9; j++)
                if (state.board[i] > state.board[j])
                    ++counter;

        return !static_cast<bool>(counter & 1);
    }

private:
    State initState;

    std::array<char, BOARD_SIZE> swapStates(const std::array<char, BOARD_SIZE> &board, int blankSwap, int indSwap)
    {
        std::array<char, BOARD_SIZE> temp1{board};
        std::array<char, BOARD_SIZE> temp2{board};

        temp1.at(blankSwap) = temp2.at(indSwap);
        temp1.at(indSwap) = temp2.at(blankSwap);

        return temp1;
    }

    std::vector<int> actionVector(int blankPos)
    {
        std::vector<int> moves;
        switch (blankPos)
        {
        case 0:
            moves = {1, 3};
            break;
        case 1:
            moves = {0, 2, 4};
            break;
        case 2:
            moves = {1, 5};
            break;
        case 3:
            moves = {4, 0, 6};
            break;
        case 4:
            moves = {3, 5, 1, 7};
            break;
        case 5:
            moves = {4, 2, 8};
            break;
        case 6:
            moves = {7, 3};
            break;
        case 7:
            moves = {6, 8, 4};
            break;
        case 8:
            moves = {7, 5};
            break;
        }
        return moves;
    }
};

struct Heuristic
{
    int operator()(const State &state)
    {
        int h{0};
        std::array<char, BOARD_SIZE> idealState = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};

        for (size_t i{0}; i < idealState.size(); ++i)
            if (state.board.at(i) != idealState.at(i))
                ++h;

        return h;
    }
};


#endif