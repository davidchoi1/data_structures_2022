#include <cstdint>
#include <functional>

#ifndef STATE_H
#define STATE_H

#define POS_MASK 0xfULL
#define GOAL_STATE 0x012345678ULL

struct PuzzleState
{
    PuzzleState();
    PuzzleState(uint64_t);
    PuzzleState(uint64_t, uint32_t);

    PuzzleState move(uint32_t) const;               // subscript
    static void swapTiles(PuzzleState& uint32_t, uint32_t);
    static PuzzleState createRandomState();
    static bool validState(const PuzzleState&);

    bool operator==(const PuzzleState&) const;
    bool operator!=(const PuzzleState&) const;
    uint64_t get(uint32_t) const;
    void set(uint32_t, uint64_t);

    uint64_t state;
    uint8_t blankPos;

};

struct StateHasher
{
    size_t operator()(const PuzzleState& s) { return std::hash<uint64_t>{}(s.state); }
}

#endif