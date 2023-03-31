#include <string>
#include <stdexcept>

#include "account_error.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

#define MIN_BALANCE 0.0

class Account
{
public:
   Account(double);

   virtual void credit(double);

   virtual void debit(double);

   double getBalance() const;
   
protected:
   double balance;
};

#endif