#include "Integer.h"
#include <iostream>

Integer ::Integer() { p_Int = new int(0); }

Integer ::Integer(int value) { p_Int = new int(value); }

/* User defined Copy Constructor */
/* If you pass an object by value, again a copy of the object will be created,
   To avoid this pass by reference */
/* Also as the obj is passed by reference, it can get modified, so always add
   const to the object so that not accidentally modified */
Integer::Integer(const Integer &obj) {
  /* Deep Copy */
  p_Int = new int(*obj.p_Int);
}

void Integer ::get() const {
  std::cout << "Integer value is: " << *p_Int << std::endl;
}
void Integer ::set(int value) { *p_Int = value; }

Integer ::~Integer() { delete p_Int; }
