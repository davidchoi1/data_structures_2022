#include <iostream>
#include <ctime>
#include <array>
#include <iomanip>

#define TEST_QTY 600000



void sumProbabilities(std::array<double, 13>&);
std::array<size_t,13> runTest();
void printResults(const std::array<size_t, 13>&, const std::array<double, 13>&);
int randRange(int, int);

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    std::array<double, 13> probs;

    sumProbabilities(probs);

    printResults(runTest(), probs);

    return 0;
}


void sumProbabilities(std::array<double, 13>& probs)
{
    const double p{1/36.0};
    for(double& p : probs) p = 0;

    for(int i{1}; i<=6; ++i)
        for(int j{1}; j <=6; ++j)
            probs[i+j] = p;
}

std::array<size_t,13> runTest()
{
    std::array<size_t, 13> sums{};

    int d1;
    int d2;

    for (size_t i = 0; i < TEST_QTY; i++)
    {
        d1 = randRange(1,6);
        d2 = randRange(1,6);
        ++sums[d1 + d2];
    }

    return sums;
    
}

void printResults(const std::array<size_t, 13>& results, const std::array<double, 13>& probs)
{
    const static int width{12};

    std::cout << std::fixed << std::setprecision(3);

    std::cout << std::setw(width) << std::left << "sum" << std::setw(width) << "total"
              << std::setw(width) << "expected" << std::setw(width) << "actual" << std::endl;

    for (size_t i{2}; i < results.size(); ++i)
    {
    std::cout << std::setw(width) << std::left << i << std::setw(width) << results[i]
              << std::setw(width) << probs[i] * 100 << "%" << std::setw(width) << static_cast<double>(results[i]) / TEST_QTY * 100 << "%\n";
    }
    
}

int randRange(int start, int end)
{
    return rand( ) % (end - start + 1) + start;
}