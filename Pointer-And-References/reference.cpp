/* Reference is an alias of a variable, No memory is created for ref variable
It is a new name to the variable
But you can change the value of the variable by dereferencing the ref variable*/

#include <iostream>

using namespace std;

int main() {
  int x = 10;
  int &ref = x; // ref is the reference and x is the referent here. Any value
                // you change for x or ref, it will reflect in both

  // always need to have a referent for initialization
  // int &ref2; // Compiler Error without referent

  // The referent should be always an lvalue, can't be 23.
  // int &ref3 = 23;

  cout << "x = " << x << endl;
  cout << "ref = " << ref << endl;

  x = 6;
  cout << "After changing the val of x to 6, ref = " << ref << endl;

  ref = 8;
  cout << "After changing the val of ref to 6, x = " << x << endl;

  // This is because: x and ref are identifiers of same memory location
  cout << "&ref = " << &ref << endl;
  cout << "&x = " << &x << endl;

  // Now have a variable y and do "ref = y" : This is change the value of ref,
  // But ref will be the same memory address of x, not of y
  int y = 5;
  ref = y;
  cout << "y = " << y << endl;
  cout << "ref = " << ref << endl;
  cout << "x = " << x << endl;

  // But the address of (ref/x) and y is different
  cout << "&y = " << &y << endl;
  cout << "&ref = " << &ref << endl;
  cout << "&x = " << &x << endl;
  return 0;
}
