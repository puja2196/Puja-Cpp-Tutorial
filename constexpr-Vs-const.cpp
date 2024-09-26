#include <iostream>

using namespace std;

int GetNumber() { return 42; }

constexpr int GetConstExprNumber() { return 42; }
/* 1. The return type of constexpr function should be literal types:
 void, scaler types(char, int, float), references etc.
   2. The function contains only one statement and that should be the
return statement
   3. C++14 removes the limitation 2.
   4. constexpr function is treated as inline function, so should be defined
in .h file
*/

constexpr int Add(int x, int y) { return (x + y); }

constexpr int FindMax(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

int main() {

  /* With constexpr, the variables are computed at compile time */
  constexpr int i = 10;
  /* the value of i can be used in those expressions which expects compile time
   * constant */
  int arr[i]; // Static array initialization: the value of i need to know in
              // compile time

  /* Not all const declared at compile time */
  /* The following declared at compile time */
  const int j = 10;
  int arr1[j];
  /* Not the following */
  const int k = GetNumber();
  /* k will be computed at runtime, so k is constant but not constexpr */
  // int arr2[k]; => You can't perform this

  /* The following can't be done: the return type of the function is not
   * constexpr, so the function is computed in runtime */
  // constexpr int l = GetConstNumber();
  /* The function "GetConstExprNumber" return type is constexpr, so the function
   * is computed in compile time and can be assigned to a constexpr */
  constexpr int l = GetConstExprNumber();

  // GetConstExprNumber() behaves as a normal function if assigned to normal
  // integer
  int x = GetConstExprNumber();

  // GetConstExprNumber() behaves as a constexpr function if assigned to
  // constant integer
  const int y = GetConstExprNumber();

  constexpr int sum = Add(3, 5); // Computed in compile time
  // constexpr int sum1 = Add(x,5); // Error: as x is computed at runtime, can't
  // be used at compile time

  int sum2 = Add(3, 4); // Computed at runtime, behaves as normal function

  constexpr int max = FindMax(5, 13); /* Should compute at compile time
   But with -std=c++11, it gives compiler error as: it can only contain one
   return statement With C++14 we don't have this issue */
}
