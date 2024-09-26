#include "Integer.h"
#include <iostream>

using namespace std;

/* Operator Overloading using Global function */
/*
Integer operator+(const Integer &a, const Integer &b) {
    Integer temp;
    temp.set(a.get()+b.get());
    return temp;
}
*/

int main() {

  Integer a{2}, b{2};
  Integer sum = a + b; // Overloading '+' Operator
  /* If we have both the overloading i.e. by class member function and global
  function, Compiler generates warning: main.cpp: In function ‘int main()’:
  main.cpp:16:23: warning: ISO C++ says that these are ambiguous, even though
  the worst conversion for the first is better than the worst conversion for the
  second: 16 |     Integer sum = a + b; // Overloading '+' Operator | ^
  main.cpp:7:9: note: candidate 1: ‘Integer operator+(const Integer&, const
  Integer&)’ 7 | Integer operator+(const Integer &a, const Integer &b) { |
  ^~~~~~~~ In file included from main.cpp:1: Integer.h:8:13: note: candidate 2:
  ‘Integer Integer::operator+(const Integer&) const’ 8 |     Integer operator +
  (const Integer &) const; |             ^~~~~~~~

  To avoid this you can comment any of this:
  */
  cout << "Sum = " << sum.get() << endl;

  cout << "Sum after pre-Incrementing = " << (++sum).get() << endl;

  cout << "Sum after post-Incrementing = " << ((sum++).get()) << endl;

  if (a == b)
    cout << "a and b are equal\n";
  else
    cout << "a and b are not equal\n";

  Integer c;
  c = a;
  cout << "c = " << c.get() << endl;
  return 0;
}
