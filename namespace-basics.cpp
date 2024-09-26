#include <iostream>

using namespace std;

/*
Schenerio 1:
Function Calculate computes AVG.

float Calculate (int x, int y)
{
    // Compute AVG
    return (x+y)/2;
}

 Someother Programmer wants a different logic for "Calculate"
 If we write with same name with same type and number of args,
 Compiler throws error
float Calculate (int x, int y)
{
    // Compute SUM
    return (x+y);
}
*/

/* Now define the functions in different namespace */
namespace Avg {
float Calculate(int x, int y) {
  // Compute AVG
  return (x + y) / 2.0f;
}
} // namespace Avg

namespace Sum {
float Calculate(int x, int y) {
  // Compute SUM
  return 1.0f * (x + y);
}
} // namespace Sum

namespace Sub {
void Calc() {}
} // namespace Sub

/* namespace with no name" */
namespace {
void Init() { cout << "from Init\n"; }
} // namespace

int main() {
  int x = 3, y = 4;
  Init(); // We can call Init without opening the namespace as no name for this
  /* To access the Calculate function of both the namespaces */
  using namespace Avg;
  float f1 = Calculate(3, 4);
  cout << "Avg = " << f1 << endl;
  /* Again opening a namespace with the same function of namespace
     Avg wont work */
  // using namespace Sum;
  // Calculate(3, 4);

  /* Use the full qualified name */
  float f2 = Sum::Calculate(3, 4);
  cout << "Sum = " << f2 << endl;

  /* Can you open the namespace "Sub"? ==> yes because Sub has no
     common function with opened namespace "Avg".
  */
  using namespace Sub;

  return 0;
}
