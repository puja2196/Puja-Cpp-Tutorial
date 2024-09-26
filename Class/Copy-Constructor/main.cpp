#include "Integer.h"
/* Copy of an object is created when a function is called with argument
   same as the object or when a function is returning the object or when
   you manually create a copy of an object */

/* a function is called with argument passing the object as value*/
void Func(Integer i) {}

/* when a function is returning the object */
Integer Func2(int x, int y) { return Integer(x + y); }

int main() {

  Integer i1(5);
  i1.get();
  /* when you manually create a copy of an object */
  Integer i2(i1);
  /* All the 3 cases copy of the object will be created but it is a shallow
     copy. Shallow Copy: i2's copy of data members won't get created, just i2
     will be pointing to i1. Example: int* p1 = new int(5); int* p2 = p1; Deep
     Copy Example: int *p3 = new int(*p1);
  */
  /* To create the deep copy of the object we need to have user-defined Copy
   * Constructor */
}
