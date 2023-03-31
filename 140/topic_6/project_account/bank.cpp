#include <iostream>

#include "account.h"
#include "savings_account.h"
#include "checkings_account.h"

#define TEST_RATE .05

int main(int argc, char const *argv[])
{
    // calculate and add interest rate to savings account
    SavingsAccount account(4.2, TEST_RATE);
    account.credit(account.calculateInterest());
    std::cout << account.getBalance() << std::endl;

    // create and test checkings account
    CheckingsAccount checkings(10, 2.50);
    checkings.credit(5);
    checkings.debit(4);
    std::cout << checkings.getBalance() << std::endl;

    // create and test Account error
    Account noAccount(-15);

    return 0;
}
