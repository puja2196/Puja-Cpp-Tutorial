#include <iostream>

using namespace std;

#define SQUARE(x) x *x

int Square(int x) { return (x * x); }

inline int Square2(int x) { return (x * x); }

int main() {
  int x = Square(5);
  cout << "x = " << x << endl;
  /* To avoid the function-overhead like function call,
     allocating stack for arguments and after call is fininshed,
     returning to correct instruction, in case of time-sensitive
     application, we use Macros for those
  */
  int y = SQUARE(5);
  cout << "y = " << y << endl;

  /* The problem with macro is as follows */
  int z = SQUARE(5 + 1); // 5+1*1+5 = 11 , but expected 36
  cout << "z = " << z << endl;

  /* So we have something called "inline function" where we tell the compiler to
     copy the body of the function in the caller to overhead function call */
  int w = Square2(5 + 1); // It is an inline function so argument is evaluated
                          // then only callee's body is placed in caller.
  cout << "w = " << w << endl;
  return 0;
}
