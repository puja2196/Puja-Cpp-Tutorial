#include <iostream>

using namespace std;

int main() {
  // Pointer Variable Declaration
  int *p; // p is a pointer variable pointing to an integer variable, p holding
          // the address of an integer variable
  int *p1, *p2, *p3, p4; // p1, p2, p3 pointer to interger, p4 is not a pointer
                         // but an integer variable bcz no *

  // Address of operator = &.
  int x = 10;
  cout << "Address of x = " << &x
       << endl; // It prints the address of x, not value of x

  // int ptr = &x; // Gives error because: ptr is an integer variable, not
  // pointer variable so that it can point to any other variable

  int *ptr = &x; // Now ptr is a pointer variable pointing to integer x, ptr
                 // holds the address of x i.e. value of ptr is address of x.
  cout << "value of ptr =" << ptr << endl;

  // Type of the pointer should match with the source.
  // float *ptr2 = &x; // Type mismatch between float* and int*.

  // Void pointers:
  /* In some cases you want to create a pointer which can point any type.
   * This is used for getting the address of a variable.
   * in that case use "void*". */
  void *ptr3 = &x;
  cout << "value of ptr3 =" << ptr3 << endl;

  /* Why we can't deference void pointer?
     Since a void* pointer has no type, the compiler doesn't know how much
     memory to dereference (e.g., 1 byte for a char, 4 bytes for an int,
     8 bytes for a double, etc.). As a result, the compiler will produce
     an error if you try to dereference it directly. */
  // cout << "*ptr3 = " << *ptr3 <<endl; // Error:

  void *ptr4; // Unitialized pointer holds random addresses or some compiler
              // generates error for those
  cout << "value of ptr4 = " << ptr4 << endl;

  // Deference Operator: * to access the address of a variable and modify the
  // value of that (R/W access)

  *ptr = 5; // ptr is pointing to a location which is written to with value "5".
  cout << "value of x = " << *ptr << endl;

  int y = *ptr; // read the value of the location where ptr is pointing to: i.e.
                // value of x
  cout << "value of y = " << y << endl;

  // NULL pointer:
  /* If we dont initialize a pointer variable with address of some other
   * variable, then how can we initialize it? Using NULL in C and Pre-C++11 In
   * C++11, a new type of null i.e. nullptr is introduced. It is type-safe and
   * better than the NULL macro. Always initialize pointer variable with
   * nullptr. */
  void *ptr5 = nullptr;

  int *ptr6 = nullptr;
  // cout << "*ptr6 = " << *ptr6 <<endl; // Segmentation fault - bcz ptr6 is a
  // nullpointer, not point to anything, so you can't read from that. *ptr6 =
  // 10; // Segmentation fault - bcz ptr6 is a nullpointer, not point to
  // anything, so you can't write to that.

  ptr6 = &x; // Now ptr6 is pointing to integer variable x, no more it is a null
             // pointer
  *ptr6 = 7; // Now we can write to the location where ptr6 is pointing to.
  cout << "x = " << x << endl;

  return 0;
}
