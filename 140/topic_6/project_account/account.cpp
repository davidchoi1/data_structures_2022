   #include "account.h"
   
   Account::Account(double accountBalance)
   {
      if (accountBalance <= MIN_BALANCE)
         throw AccountError("Error: Attempted add below minimum allowable balance.");

      balance = accountBalance;
   }

   void Account::credit(double addAmount)
   {
      balance += addAmount;
   }

   void Account::debit(double withdrawAmount)
   {
      if (withdrawAmount >= balance)
         throw AccountError("Error: Attempted to withdraw amount greater than balance.");

      balance -= withdrawAmount;
   }

   double Account::getBalance() const
   {
      return balance;
   }
