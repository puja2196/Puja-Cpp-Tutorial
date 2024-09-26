#include "Integer.h"

#include <iostream>

using namespace std;

void Print(Integer a) {}

void Print2(const Integer &a) {}

int main() {
  /* Constructor can be used to convert from primitive type int to User defined
   * type: Integer */
  Integer a1{
      5}; // No Type Conversion, just the parameterized constructor called.

  /* Examples of type conversions */
  /* Initialization */
  Integer a2 =
      6; // Integer a2 = Integer(6) => search for parameterized constructor with
         // int and invoke it and it will work as it is present.
  // Integer a3 = "abc"; // Doesnt work, as No parameterized constructor with
  // char[4]

  Print(5); // This call will typecast 5 using Integer(5) while passing as
            // argument.
            /* As this is Call by Value, it will call Integer(int).*/

  Print2(6); // This is call by reference, int 6 should be type casted Integer
             // and its address should be paased to the function. so it will
             // call parameterized Constructor,=> Integer(int).

  /* Assignment */
  a2 = 7;
  /* a2 = Integer(7)=> calls Integer(int), then it's assigned.
  Here for the "=" operator, argument is r-value, This is the function:
  operator=(&&) => Move assignment operator will be called. */

  /* If you mark the constructor in .h file as "explicit":
     then you can't use that constructor for type-conversion:
     So No other statements work except the first one and report error:
     conversion from ‘int’ to non-scalar type ‘Integer’ requested
   */
  return 0;
}
