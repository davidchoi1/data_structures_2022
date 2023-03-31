#include "state_prob_heur.h"

#ifndef ANODE_H
#define ANODE_H

struct Anode
{
    Problem problem;
    Heuristic heuristic;
    Anode *parent;
    State state;
    size_t pathCost{0};
    size_t estCost{0};

    Anode(Problem problem, Heuristic heuristic, Anode *parent, State state) : problem{problem}, heuristic{heuristic}, parent{parent}, state{state}
    {
        // calculate pathcost dependant on problem step cost ?? is this right ??
        while (parent != nullptr)
        {
            pathCost += problem.stepCost();
            parent = parent->parent;
        }
        // calculate estimated cost of state in node
        estCost = pathCost + heuristic(state);
    }

    Anode(Problem problem, Heuristic heuristic, Anode *parent) : Anode(problem, heuristic, parent, problem.initialState()) {}

    Anode(Problem problem, Heuristic heuristic) : Anode(problem, heuristic, nullptr, problem.initialState()) {}

    bool operator==(const Anode &other) { return state == other.state; }
    bool operator!=(const Anode &other) { return !(*this == other); }
};


struct EstCostOrder
{
    bool operator()(Anode *a, Anode *b) { return a->estCost > b->estCost; }
};

struct AnodeHasher
{
    int operator()(Anode *a) const { return a->state.hashCode; }
};

struct AstarError : public std::runtime_error
{
    AstarError() : std::runtime_error("Error occurred in Astar") {}

    AstarError(const char *msg) : std::runtime_error(msg) {}
};

#endif