#include "Transaction.h"
#include "Account.h"
#include "Checkings.h"
#include <iostream>

using namespace std;

void TransactwithParamCheckings(Checkings *account) {
  cout << "Transaction using function taking account as Checkings type\n";
  cout << "Initial Balance: " << account->Getbalance() << endl;
  account->Deposit(100);
  account->AccumulateInterest();
  account->Withdraw(170);
  cout << "Interest rate: " << account->GetInterestRate() << endl;
  cout << "Current Balance: " << account->Getbalance() << endl;
}

void TransactwithParamAccount(Account *account) {
  cout << "Transaction using function taking account as Account type\n";
  cout << "Initial Balance: " << account->Getbalance() << endl;
  account->Deposit(100);
  account->AccumulateInterest();
  account->Withdraw(170);
  cout << "Interest rate: " << account->GetInterestRate() << endl;
  cout << "Current Balance: " << account->Getbalance() << endl;
}
