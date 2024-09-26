#include "utility-functions.h"
#include <iostream>

using namespace std;

int main() {
  int x = 2, y = 3;
  int result1;

  // 1st Function
  Add(x, y, result1);
  cout << "result1 = " << result1 << endl;

  // 2nd Function:
  int input;
  int result2 = 1;
  cout << "Enter the number you want to compute factorial for???  ";
  cin >> input;
  Factorial(input, result2);

  cout << "result2 = " << result2 << endl;

  // 3rd Function:
  cout << "Before swapping:===>\n";
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;

  Swap(x, y);

  cout << "After swapping:===>\n";
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;
  return 0;
}
