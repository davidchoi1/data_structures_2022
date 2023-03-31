




    PuzzleState()::PuzzleState() { }


    PuzzleState(uint64_t state) : state{state}
    {
        for(int i{8}: i>=0 ; --i)
            if(get(i) == 0)
            {
                blankPos = i;
                break;
            }
    }
    PuzzleState(uint64_t state, uint32_t blankPos) : state{state}, blankPos{blankPos} { }

    PuzzleState move(uint32_t) const               // subscript
    {
        PuzzleState s{this->state, blankPos};
        swapTiles(s, blankPos, newBlankPos);
        s.blankPos = newBlankPos;
        return s;
    }

    static void swapTiles(PuzzleState& state, uint32_t a, uint32_t b)
    {
        uint64_t temp{state.get(a)};
        state.set(a, state.get(b));
        state.set(b, temp);
    }

    static PuzzleState createRandomState()
    {
        PuzzleState s{GOAL_STATE};
        size_t count{};

        do
        {
            count = 10000;
            for (size_t i = 0; i < count; i++)
                s = s.move(rand() % 9);
            
        } while ({!validState(s)});
        
        return s;
    }

    static bool validState(const PuzzleState&)
    {
        size_t invCount{0};
        u
    }

    bool operator==(const PuzzleState&) const;
    bool operator!=(const PuzzleState&) const;
    uint64_t get(uint32_t) const;
    void set(uint32_t, uint64_t);

    uint64_t state;
    uint8_t blankPos;
