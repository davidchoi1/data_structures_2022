#include "savings_account.h"

SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance), interestRate{interestRate} {}

double SavingsAccount::calculateInterest()
{
    return interestRate * balance;
}