#include "Savings.h"
#include <iostream>
#include <typeinfo>

using namespace std;

int main() {

  Savings s1{"Alice", 100, 0.05f};

  int m{};
  float fl{};

  const type_info &ti = typeid(m);
  cout << "ti(m).name = " << ti.name() << "\n"; // i => int

  const type_info &ti1 = typeid(fl);
  cout << "ti(fl).name = " << ti1.name() << "\n"; // f => float

  const type_info &ti2 = typeid(s1);
  cout << "ti(s1).name = " << ti2.name() << "\n"; // Savings Class

  Account a2 = s1;
  const type_info &ti5 = typeid(a2);
  cout << "ti(a2).name = " << ti5.name() << "\n"; // Account

  Account *a1 = &s1;
  const type_info &ti3 = typeid(a1);
  cout << "ti(a1).name = " << ti3.name()
       << "\n"; // ti(a1).name = P7Account => Pointer to Account

  const type_info &ti4 = typeid(*a1);
  cout << "ti(*a1).name = " << ti4.name() << "\n"; // Savings Class

  // Use Comparison operator
  if (ti4 == typeid(Savings)) {
    cout << "Pointing to Savings class\n";
  }

  return 0;
}
