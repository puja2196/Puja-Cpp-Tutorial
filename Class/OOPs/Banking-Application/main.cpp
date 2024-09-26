// #include "Account.h"
#include "Checkings.h"
#include "Savings.h"
#include "Transaction.h"
#include <iostream>

using namespace std;

int main() {

  /* Account testing */
  /*
      Account a1{"Bob", 1000};
      cout << "Initial Balance of a1: " << a1.Getbalance()<< endl;

      a1.Withdraw(1200);
      a1.Deposit(200);
      cout << "Current Balance of a1: " << a1.Getbalance()<< endl;
  */
  /* Savings testing */
  /*
      Savings s1{"Alice", 130, 0.5f};
      cout << "Initial Balance of s1: " << s1.Getbalance()<< endl;

      s1.Withdraw(120);
      s1.AccumulateInterest();
      s1.Deposit(200);
      cout << "Current Balance of s1: " << s1.Getbalance()<< endl;
  */
  /* Checkings testing */
  /*
      Checkings c1{"Carter", 450};
      cout << "Initial Balance of c1: " << c1.Getbalance()<< endl;
      c1.Withdraw(430);

      cout << "Current Balance of c1: " << c1.Getbalance()<< endl;
      c1.Deposit(200);
      cout << "Current Balance of c1: " << c1.Getbalance()<< endl;

      Checkings c2{"Doll", 100};
      TransactwithParamCheckings(&c2);

      Checkings c3{"Elite", 100};
      TransactwithParamAccount(&c3);
  */
  /* Both the behaviours are different, bcz:
     TransactwithParamCheckings calling Checkings::Withdraw()
     TransactwithParamAccount calling Account::Withdraw()
     As we can't call TransactwithParamCheckings with Savings param type:
     TransactwithParamCheckings(s1);

     We need to use TransactwithParamAccount() and to make the parameter Account
     to use "Withdraw" method (overrided) from Checkings, we need to override
     all the implemented functions in derived class using "virtual" keyword
     while defining in Base class. Using virtual keyword indicates even though
     the pointer type is Account type, it doesn't know in compile time: what
     kind of objects it is pointing to i.e. Current or Savings */

  /* Instead of creating a local object, let's create the object in heap */
  Savings *s2 = new Savings{"Puja", 100, 0.05f};
  delete s2;
  /* The output is:
  Account::Account
  Savings::Savings
  Savings::~Savings
  Account::~Account
  */
  /* As Base class pointer can point to child class object, so */
  Account *a3 = new Savings{"Puja", 100, 0.05f};
  delete a3;
  /* Without virtual destructor in Account:
  The Output is:
  Account::Account
  Savings::Savings
  Account::~Account

  Here the child object destructor is not called, because Compiler is generating
  destructor call based on the pointer type: i.e. Account, But to know the type
  of the object we want to destroy, we need virtual destructor And Now the
  output is: Account::Account Savings::Savings Savings::~Savings
  Account::~Account

  */
  return 0;
}
