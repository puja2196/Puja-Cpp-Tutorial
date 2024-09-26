#include "Checkings.h"
#include <iostream>

using namespace std;

/*
Checkings::Checkings(const string &n, float amount) : Account(n,amount) {
}
*/

Checkings::~Checkings() {}

void Checkings::Withdraw(float amount) {
  if (balance - amount >= 50) {
    // balance-=amount;
    /* Another way to implement this is: calling parent class function here */
    Account::Withdraw(amount);
  } else {
    cout << "Insufficient Balance, balance can't fall under 50\n";
  }
}
