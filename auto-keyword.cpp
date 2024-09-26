#include <iostream>

using namespace std;

int Sum(int x, int y) { return (x + y); }

int main() {
  auto i = 10;
  // Auto declaration needs an initializer.
  // auto j; // error : declaration of ‘auto j’ has no initializer
  auto j = 5;

  // Initializer is an expression
  auto k = (i + j);

  // If types are different of the operands of the expression, type of auto
  // variable will become the type with max size
  auto sum = i + 3.45f; // Sum has the type "float"

  // Initializer is a function call
  auto result = Sum(i, j); // Compiler will infer the type of "result" by
                           // looking at the return type of the function.

  const int x = 10;
  auto var = x; // Initializing an auto with constant discards the constantness
                // and var is not constant
  const auto var2 = x; // Now var2 is constant

  auto &ref =
      x; // ref is a reference of x, as x is constant, ref is also constant.

  auto ptr1 =
      &x; // Constantness is not discarded, ptr1 is pointer to constant int.
  /*** Note its not *ptr1 but ptr1, To avoid confussion, best practice not using
    *auto with pointers and references.
  ***/

  auto list = {1, 2, 3, 5}; // Initializer list

  // auto list2{1,2,3,5}; // for deduction to ‘std::initializer_list’, use
  // copy-list-initialization (i.e. add ‘=’ before the ‘{’) OR,
  auto list3{3}; // list3 will be treated as integer.

  return 0;
}
