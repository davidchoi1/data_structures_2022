#include "checkings_account.h"

CheckingsAccount::CheckingsAccount(double balance, double chargeFee) : Account(balance), chargeFee{chargeFee} {}

void CheckingsAccount::credit(double addAmount)
{
    balance -= chargeFee;
    balance += addAmount;
}

void CheckingsAccount::debit(double withdrawAmount)
{
    if (withdrawAmount + chargeFee >= balance)
        throw AccountError("Error: Attempted to withdraw amount greater than balance.");

    balance -= (chargeFee + withdrawAmount);
}
