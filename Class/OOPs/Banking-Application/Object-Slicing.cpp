#include "Checkings.h"
#include "Savings.h"
#include <iostream>

using namespace std;

int main() {
  Savings s1{"Alice", 100, 0.05f};

  /* As Savings object copied to Account object, object slicing happens */
  Account a1 = s1;
  cout << a1.GetInterestRate() << endl; // Returns 0

  // Upcasting:
  /* Pointer of Account object type pointing to Savings object */
  Account *a2 = &s1;
  cout << a2->GetInterestRate() << endl; // Returns 0.05

  /* There is error for the follwing bcz not all Accounts is Savings Account:
  Savings *s2 = a2;
  */

  // Downcasting
  Savings *s2 = static_cast<Savings *>(a2);
  return 0;
}
