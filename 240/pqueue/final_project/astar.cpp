#include "state_prob_heur.h"



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


linear data structure -> comes after queues stacks and deques

class Astar
{
public:
    Astar(const Problem &problem, const Heuristic &heuristic) : anode{nullptr}, childNode{nullptr}, problem{problem}, heuristic{heuristic} {}

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
                throw AstarError("ERROR: Astar frontier empty");

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
                if (!(explored.find(childNode) != explored.end()))
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

int main(int argc, char const *argv[])
{
    std::array<char, BOARD_SIZE> board{'1', '7', '3', '2', '8', '4', '6', '5', '0'};
    State state(board);
    Problem problem(state);
    Heuristic heuristic;

    Anode anode(problem, heuristic);

    std::cout << anode.pathCost << std::endl;
    



    
    return 0;
}