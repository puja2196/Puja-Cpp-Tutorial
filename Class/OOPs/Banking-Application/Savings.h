#include "Account.h"

class Savings : public Account {
  float rate;

public:
  Savings(const string &n, float amount, float rate);
  ~Savings();
  void AccumulateInterest();
  float GetInterestRate() const;
};
