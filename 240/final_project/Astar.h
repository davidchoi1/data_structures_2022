#include "Anode.h"

#ifndef ASTAR_H
#define ASTAR_H




class Astar
{
public:
    Astar(const Problem &problem, const Heuristic &heuristic) : anode{nullptr}, childNode{nullptr}, problem{problem}, heuristic{heuristic} {}


    void print()
    {
        Anode* itr{anode};
        while (itr != nullptr)
        {
            std::cout << itr->state.hashCode << "->";
            itr = itr->parent;
        }
        std::cout << '\n';
    }


    Anode *Asearch()
    {
        // if initial state in problem can't be solved, throw error
        if (!(problem.isValid(problem.initialState())))
            throw AstarError("ERROR: Invalid state");

        // put initial node in frontier
        frontier.emplace(anode);

        // create transVector to hold state transitions
        std::vector<State *> transVector;

        do
        {
            // if frontier is empty, throw error
            if (frontier.empty())
                return nullptr;

            // create new anode whose parent is the the next anode in the frontier
            anode = new Anode(problem, heuristic, frontier.top());
            frontier.pop();

            // if anode contains goal state, return it
            if (problem.goalTest(anode->state))
                return anode;

            // otherwise, place node into explored
            explored.emplace(anode);

            // populate transVector with anode's state's transition states
            transVector = problem.stateTransitions(anode->state);
            // for each transitioned state...
            for (size_t i{0}; i < transVector.size(); i++)
            {
                // create childnode containing parent's problem, heuristic, and statetransition -> pointing at parent,
                childNode = new Anode(anode->problem, anode->heuristic, anode, *transVector.at(i));

                // if new anode is not already in explored set, place into frontier
                if (explored.find(childNode) == explored.end())
                    frontier.emplace(childNode);
            }

        } while (true);
    }

private:
    Anode *anode;
    Anode *childNode;
    Problem problem;
    Heuristic heuristic;
    std::priority_queue<Anode *, std::vector<Anode *>, EstCostOrder> frontier;
    std::unordered_set<Anode *, AnodeHasher> explored;
};

#endif