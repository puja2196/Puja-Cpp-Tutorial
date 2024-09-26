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

/* Copy Constructor */
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

Integer &Integer::operator=(const Integer &obj) { // Copy Assignment
  cout << "operator=(const Integer &)" << endl;
  if (this == &obj)
    return *this;
  delete p_Int;
  p_Int = new int(*obj.p_Int);
  return *this;
}

Integer &Integer::operator=(Integer &&obj) { // Move Assignment
  cout << "operator=(Integer &&)" << endl;
  if (this == &obj)
    return *this;
  delete p_Int;
  p_Int = obj.p_Int;
  obj.p_Int = nullptr;
  return *this;
}

Integer::operator int() { return *p_Int; }

int Integer ::get() const { return *p_Int; }
void Integer ::set(int value) { *p_Int = value; }

Integer ::~Integer() {
  cout << "~Integer()" << endl;
  delete p_Int;
}
