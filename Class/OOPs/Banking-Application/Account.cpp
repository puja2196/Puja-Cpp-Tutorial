#include "Account.h"
#include <iostream>

using namespace std;

int Account::acc_no_generator = 1000;

Account::Account(const string &n, float ammount) : name{n}, balance{ammount} {
  // cout << "Account::Account\n";
  acc_no = ++acc_no_generator;
}

Account::~Account() {
  // cout << "Account::~Account\n";
}

const string Account::Getname() const { return name; }

int Account::Getaccno() const { return acc_no; }

float Account::Getbalance() const { return balance; }

void Account::AccumulateInterest() { // Different for different Accounts :
                                     // savings, checkings, It will be
                                     // implemented by child classes
}

void Account::Withdraw(float amount) {
  if (amount <= balance) {
    balance -= amount;
  } else {
    cout << "Insufficient Balance\n";
  }
}

void Account::Deposit(float amount) { balance += amount; }

float Account::GetInterestRate()
    const { // Different for different Accounts : savings, checkings, It will be
            // implemented by child classes
  return 0.0f;
}
