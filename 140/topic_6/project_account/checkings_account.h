#include "account.h"

class CheckingsAccount : public Account
{
public:
    CheckingsAccount(double, double);
    void credit(double);

    void debit(double);
private:
    double chargeFee;
};