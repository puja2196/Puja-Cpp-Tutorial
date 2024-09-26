#include "Integer.h"
#include <iostream>

using namespace std;

int main() {
  Integer a1{5};
  int x = a1;
  /* This gives error
     To typecast an object of Integer class to primitive int type,
     we need to implement a Type Conversion Operator function for Integer
     class
     If you make this function "explicit" in the declaration, the above will
     give error:
     So explicitely specify:
  */
  int y = static_cast<int>(a1);

  return 0;
}
