#include "account.h"

#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

class SavingsAccount : public Account
{
public:
    SavingsAccount(double, double);

    double calculateInterest();

private:
    double interestRate;
};

#endif