#include <iostream>

using namespace std;

int main() {
  /* First Exercise:
  //Try to modify x1 & x2 and see the compilation output
  int x = 5 ;
  const int MAX = 12 ;
  int &x1 = x ;
  const int &x2 = x ;
  */
  int x = 5;
  const int MAX = 12;
  int &x1 = x;

  x1 = 6;
  cout << "x1 = " << x1 << endl;
  cout << "x = " << x << endl;

  const int &x2 = x;
  // As x2 is a constant reference, it can't be modified.
  // x2 = 7; // Error

  /* 2nd Exercise:
  //Try to modify the pointer (e.g. ptr1) and the pointee value (e.g. *ptr1)
  const int *ptr1 = &x ;
  int *const ptr2 = &x ;
  const int * const ptr3 = &x ;
  */
  const int *ptr1 = &x;
  // Try to modify the pointee value (*ptr1)
  // *ptr1 = 4; // *ptr1 is constant and ptr1 is not constant
  // Try to modify the pointer (ptr1)
  int y = 4;
  ptr1 = &y;

  int *const ptr2 = &x;
  // Try to modify the pointer (ptr2)
  // ptr2 = &y; // ptr2 is constant here, not *ptr2, so we can modify that
  *ptr2 = 8;

  const int *const ptr3 = &x;
  // Here both ptr3 and *ptr3 are constant, so can't modify any.
  // ptr3 = &y; // error
  // *ptr3 = 2; // error

  /* 3rd Exercise: Find which declarations are valid. If invalid, correct the
   * declaration
   */
  const int *ptr4 = &MAX; // Valid, ptr4 is pointing to "MAX", which is constant
                          // and declaring the pointer as const int makes that
                          // *ptr4 is constant and can't be modified.

  // int *ptr5 = &MAX ; // Invalid, To make it valid, use:
  const int *ptr5 = &MAX;

  const int &r1 = x1; // Valid, x1 is a ref and r1 is constant reference of x1.
                      // You can't change the value of x1 through r1.
  // int &r2 = x2 ; // Invalid, x2 is a constant variable, so the reference of
  // x2 should be constant. So make it as:
  const int &r2 = x2;

  // int *&p_ref1 = ptr1 ; // Inavalid, ptr1 is a pointer pointing to a
  // constant, ptr1 is not constant but *ptr1 is constant, p_ref1 is reference
  // to the pointee (i.e. *ptr1). As this is a constant, so p_ref1 should be
  // decalred with const.
  const int *&p_ref1 = ptr1;

  // const int* &p_ref2 = ptr2 ; // ptr2 is a constant pointer, but not *ptr2.
  // p_ref2 is a reference which expects a referent that is a pointer pointing
  // to a constant integer. But ptr2 is a constant pointer to integer. Because
  // of the type mismatch its invalid. To make it valid: p_ref2 type should be
  // const int* i.e. p_ref2 should be a constant pointer to an integer.
  int *const &p_ref2 = ptr2;

  return 0;
}
