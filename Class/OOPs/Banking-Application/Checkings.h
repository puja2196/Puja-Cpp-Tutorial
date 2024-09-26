#include "Account.h"

class Checkings : public Account {
public:
  // Checkings(const string &n, float amount);
  /* Here the child class doesnt have its own attribute and need to call the
     constructor of the base=> That can be done using inheriting constructors.
     Instead of implementing Checkings own Constructor(which just is used to
     call the Base class Account constructor), we can simply inherit all the
     Account constructors */
  using Account::Account;
  ~Checkings();
  void Withdraw(float amount);
};
