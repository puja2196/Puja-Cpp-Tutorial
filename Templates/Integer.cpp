#include "Integer.h"
#include <iostream>

using namespace std;

Integer ::Integer() {
  cout << "Integer()" << endl;
  p_Int = new int(0);
}

Integer ::Integer(int value) {
  cout << "Integer(int)" << endl;
  p_Int = new int(value);
}

/* User defined Copy Constructor */
/* If you pass an object by value, again a copy of the object will be created,
   To avoid this pass by reference */
/* Also as the obj is passed by reference, it can get modified, so always add
   const to the object so that not accidentally modified */
Integer::Integer(const Integer &obj) {
  cout << "Integer(const Integer &)" << endl;
  /* Deep Copy */
  p_Int = new int(*obj.p_Int);
}

/* Move Constructor */
Integer::Integer(Integer &&obj) {
  cout << "Integer(Integer &&)" << endl;
  // Steal the Pointer
  p_Int = obj.p_Int;
  obj.p_Int = nullptr;
}

int Integer ::get() const { return *p_Int; }
void Integer ::set(int value) { *p_Int = value; }

Integer ::~Integer() {
  cout << "~Integer()" << endl;
  delete p_Int;
}
