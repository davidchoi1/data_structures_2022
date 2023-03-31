#include <iostream>
#include <iomanip>
#include <cmath>

#define BEGINNING_SIZE 1000000000
#define END_SIZE 2500000000

int main(int argc, char const *argv[])
{
    size_t months(0);
    double amount{BEGINNING_SIZE};

    std::cout << "Rate" << std::setw(21) << "Months to 2.5 Billion Users" << std::endl;

    std::cout << std::fixed << std::setprecision(0);

    for (double rate{2}; rate <= 5; ++rate)
    {
        while (amount <= END_SIZE)
        {
            ++months;
            amount = amount + (amount * (rate / 100));
        }

        std::cout << rate << "%" << " " << months << std::endl;
    }

    return 0;
}
