#include <iostream>

#include "utility-functions.h"

using namespace std;

int main() {

  int x = 2, y = 3, dummy;
  int *a = &x;
  int *b = &y;

  // 1st Function: takes pointer variables as argument and return an integer
  int result1 = Add(a, b);
  cout << "result1 = " << result1 << endl;

  // 2nd Function: takes pointer variables as arg and return the computation via
  // third pointer argument
  int *result2 = &dummy;
  AddVal(a, b, result2);
  cout << "*result2 = " << *result2 << endl;

  // 3rd Function: take 2 pointer variables and swap their value
  cout << "=== Before swaping ===\n";
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;

  Swap(a, b);
  cout << "=== After swaping ===\n";
  cout << "x = " << x << endl;
  cout << "y = " << y << endl;

  // 4th function: take a pointer variable as argument and compute factorial and
  // store the result in another pointer argument
  int input;
  cout << "Enter the number you want to get factorial of????";
  cin >> input;
  int *number = &input;

  int base = 1;
  int *result = &base;
  Factorial(number, result);
  cout << "Factorial of the input is: " << *result << endl;
  return 0;
}
