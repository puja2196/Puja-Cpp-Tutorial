#pragma once
#include <string>
using namespace std;

class Account {
  string name;
  // float balance; // bcz it's accessed from child class method
  int acc_no;
  static int acc_no_generator;

protected:
  float balance;

public:
  Account(const string &n, float ammount);
  virtual ~Account();
  const string Getname() const;
  int Getaccno() const;
  float Getbalance() const;

  virtual void
  AccumulateInterest(); // AccumulateInterest is implemented in Child class
                        // "Savings", hence made "virtual"
  virtual void Withdraw(float amount);
  void Deposit(float amount);
  virtual float GetInterestRate() const;
};
