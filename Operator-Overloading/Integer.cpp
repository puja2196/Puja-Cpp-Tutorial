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

Integer Integer::operator+(const Integer &obj) const {
  Integer i1;
  *i1.p_Int = *p_Int + *obj.p_Int;
  return i1;
}

Integer &Integer::operator++() {
  ++(*p_Int);
  return *this;
}

Integer Integer::operator++(int) {
  Integer temp(*this);
  ++(*p_Int);
  return temp;
}

bool Integer::operator==(const Integer &obj) const {
  return (*p_Int == *obj.p_Int);
}

Integer &Integer::operator=(const Integer &obj) {
  /* Check for self assignment "a = a": otherwise it will delete the original
   * object */
  if (this != &obj) {
    delete p_Int;
    p_Int = new int{*obj.p_Int};
  }
  return *this;
}

void Integer::operator()() {
  cout << "I am function operator: I can perform anything\n";
}

int Integer ::get() const { return *p_Int; }

void Integer ::set(int value) {
  if (p_Int == nullptr)
    p_Int = new int{};
  *p_Int = value;
}

Integer ::~Integer() {
  cout << "~Integer()" << endl;
  delete p_Int;
}
