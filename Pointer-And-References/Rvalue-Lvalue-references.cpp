#include <iostream>
using namespace std;

/* Function return by value i.e. returns r-value */
int Add(int x, int y) { return (x + y); }

/* Function return by reference i.e. returns l-value */
int &Transform(int &x) {
  x *= x;
  return x;
}

/* Function taking l-value reference */
void Print(int &x) { cout << "Print(int &)" << endl; }

/* Function taking constant l-value reference */
void Print(const int &x) { cout << "Print(const int &)" << endl; }

/* Function taking r-value reference */
void Print(int &&x) { cout << "Print(int &&)" << endl; }

int main() {
  /* R-value reference created using && */
  int &&rval_r1 =
      10; // 10 is a temporary and rval_r1 is r-value reference to it.
  int &&rval_r2 = Add(7, 2); // Add is return by value, i.e. temporaries, so can
                             // bind R-value refernce rval_r2 to it.

  /* We can't bind r-value reference to an l-value */
  int x = 1;
  /* Here x has l-value, so r-value reference can't be bind to x */
  // int &&rval_r3 = x; // Error

  /* L-value reference */
  int &lval_r1 = x;            // Can be bound to a l-value
  int &lval_r2 = Transform(x); // Can be bound to a function returning l-value
  const int &lval_r3 = 3;      // Can be bound to temporaries if it is constant.

  Print(x); // As x is an l-value, so it will be matching with the function
            // taking l-value as argument
  Print(3); /* As 3 is an r-value,
              Case 1- If the Print with argument as r-value reference is not
              there, it will be matching with Print with argument as constant
              l-value reference Otherwise - Match with the Print with argument
              as r-value reference
            */
  return 0;
}
