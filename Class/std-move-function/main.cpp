#include "Integer.h"
#include <iostream>

using namespace std;

void Print(Integer temp) {}

int main() {
  Integer a{1};
  // auto b{a};
  /* This will call Copy Constructor:  Integer(const Integer &) */

  /* To use Move Constructor, instead of Copy Constructor, use std::move */
  // auto b{static_cast<Integer&&>(a)}; // Called Integer(Integer &&)
  /*or*/
  // auto b{std::move(a)}; // Called Integer(Integer &&)

  /* Usage of std::move */
  // Print(a); // Called Integer(const Integer &)
  /* The above will create an Integer object and invoke Copy-constructor and
     create a copy of the object while passing the parameter.
     In some point of the program, if we destroy "a", still the object copied
     remains and only gets destroyed at the end of the program.

     To avoid this, if you know you don't need to read the value of "a" at later
     point, use std::move(a) while passing to Print. This will invoke
     Move-constructor, an object is created, by move operation, all the pointers
     are pointing to the pointers of the object "a". And "a" is pointing to
     nullptr now.
  */
  Print(std::move(a)); // called Integer(Integer &&)

  /* You can't read from "a" now */
  // cout << "Value is" << a.get() << endl; // Seg fault

  /* But you can reuse and reinitialize "a" */
  /* As set function doesnt handle nullptr, we need to handle the case by
   * creating a int pointer for the data member */
  a.set(4);

  cout << "Value is" << a.get() << endl; // Now No seg-fault
  return 0;
}
