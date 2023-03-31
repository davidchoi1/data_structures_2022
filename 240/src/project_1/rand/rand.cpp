#include<iostream>
#include<cstdlib>
#include<ctime>


int randRange(int,int);                                           // takes in beginning and end of range

int main(int argc, char const *argv[])
{
    int counter{0};
    srand(time(NULL));

    for (size_t i{0}; i < 1000; ++i)
    {
        if(randRange(1, 1000) <= 35) 
            {
                std::cout << "a new person entered the building\n";
                ++counter;
            }
    }

    std::cout << counter << std::endl;
     
    return 0;
}

int randRange(int start, int end)
{
    return (rand() % (end - start + 1)) + start;                    // mod random number by scaling factor and shift up by one to return 
}
