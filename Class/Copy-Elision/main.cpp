#include "Integer.h"
#include <iostream>

using namespace std;

Integer Add(int a, int b) {
  Integer i1(a + b);
  return i1;
}

int main() {
  // Integer i1 = 3;
  /* If we compile without any flag: Compiler will perform copy/move elision
  depending on the expression. The above expression is a move expression:
  because Copying a temporary/r-value. So Compiler will perform Move-elision.

  Output:
  Integer(int)
  ~Integer()

  Integer i1=3; => As 3 is of primitive type and different from class "Integer"
  type, Compiler will do typecasting before assignment: Integer i1=Integer(3);
  => Then as Compiler will perform Move-Elision, instead of creating an object
  with 3 and returning by calling Move Constructor, it will create an object of
  Integer(3).i.e. deducing to: Integer i1(3). so Integer(int) is invoked.

  Now if we compile the program: g++ -fno-elide-constructors -std=c++11
  Integer.cpp main.cpp

  Output:

  Integer(int)
  Integer(Integer &&)
  ~Integer()
  ~Integer()

  Compiler won't perform Move-elision here, so create an Integer object with 3
  (Integer(int) is invoked) and returning by calling Move Constructor
  "Integer(Integer &&)".

  */

  Integer i2 = Add(2, 3);
  /* When Copy elision is On, Compiler will disable the Move operations: So
  Output is:

  Integer(int) => Only when object is created in "Add" with parameterized
  Constructor ~Integer()

  When Copy Elision is off: Compiler will call "Integer(int)" in "Add", then
  as returning temporary value, it will call Move constructor and after
  returning in the main, while copying temporary value returned to i2, it will
  again call the Move Constructor. Output:

  Integer(int)
  Integer(Integer &&)
  ~Integer()
  Integer(Integer &&)
  ~Integer()
  ~Integer()

  For some compilers in Debug Mode when copy-elision is off, they perform
  Return-Value-Optimization(RVO), i.e. Compiler will call "Integer(int)" in
  "Add", it won't create a temporary object while returning, rather it will
  return the object created in "Add". Then after returning, only while
  assigning, it will call the Move Constructor.

  Output:
  Integer(int)
  Integer(Integer &&)
  ~Integer()
  ~Integer()

  */
  return 0;
}
