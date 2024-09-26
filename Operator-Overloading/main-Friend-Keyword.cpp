#include "Integer.h"

#include <iostream>

using namespace std;

// To make 5+a work:
Integer operator+(int x, const Integer &obj) {
  Integer temp;
  temp.set(x + obj.get());
  return temp;
}

// << operator overloading:
ostream &operator<<(ostream &out, const Integer &obj) {
  out << obj.get();
  return out;
}

istream &operator>>(istream &in, Integer &obj) {
  int x;
  in >> x;
  /* Suppose our class doesn't have set method, then how can we access private
   * data members of Integer obj. */
  // obj.set(x);
  *(obj.p_Int) = x;
  /* p_Int is private data member, so can't access from this function, so make
     the function as "friend" of the Integer class, so that the function can
     access private, protected and public datamembers of Integer friend
     definition can be done in .h file */
  return in;
}

int main() {
  Integer a{1}, b{2};
  Integer c = a + 5; // a.operator+(5); => 5 is typecasted to Integer 5.
  Integer d =
      5 + a; // 5.operator+(a); => 5 is of primitive int type and dont have
             // operator+ function. so Error without the global function with
             // 1st argument int and 2nd argument of type Integer
  cout << "d = " << d << endl;

  Integer e{};
  cout << "Enter e value:  ";
  cin >> e;
  cout << "e = " << e << endl;

  e(); // Function operator invokation
  return 0;
}
