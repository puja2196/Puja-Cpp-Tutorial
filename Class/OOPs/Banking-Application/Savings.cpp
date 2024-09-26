#include "Savings.h"
#include <iostream>

using namespace std;

Savings::Savings(const string &n, float amount, float r)
    : Account(n, amount), rate{r} {
  // cout << "Savings::Savings\n";
}

Savings::~Savings() {
  // cout << "Savings::~Savings\n";
}

void Savings::AccumulateInterest() {
  balance += rate * balance;
  /* As balance need to be accessed from child class of Account, it can't be
   * private, so should be protected */
}

float Savings::GetInterestRate() const { return rate; }
