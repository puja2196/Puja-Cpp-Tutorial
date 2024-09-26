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
  obj.set(x);
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
