#include <iostream>

using namespace std;

int main() {
  const float PI{3.14141f};
  // It replaces macros, better practice to make the name full uppercase

  // You can't modifier the variable
  // PI = 2.6f; error: assignment of read-only variable ‘PI’

  // Always need an initializer
  // const float PI2; // error: uninitialized ‘const PI2’

  // Const qualifier with pointers and references:

  const int SIZE = 5;
  // int *ptr1 = &SIZE; // A non-constant pointer can't point to constant
  // variable otherwise the pointer could change the value of the variable
  const int *ptr2 = &SIZE;
  // This means ptr2 is a pointer which is pointing to a constant variable, the
  // pointer variable is not constant Here ptr2 is not constant but *ptr2 is
  // constant.

  cout << "SIZE = " << SIZE << endl;
  cout << "*ptr2 = " << *ptr2 << endl;

  // *ptr2 = 10; //error: assignment of read-only location ‘* ptr2’

  /* Now I create a variable and make ptr2 to point to that */
  int x = 6;
  ptr2 = &x;

  // Now can you change *ptr2?
  // *ptr2 = 4; // Can't change: because ptr2 is constant pointer, so you can't
  // change the value of a variable by a constant pointer.

  cout << "SIZE = " << SIZE << endl;
  cout << "x = " << x << endl;
  cout << "*ptr2 = " << *ptr2 << endl;

  const int *const ptr3 = &SIZE;
  /* ptr3 is a constant pointer variable which is pointing to a constant
  variable ptr3 is constant and *ptr3 is constant */

  // ptr3 = &x; // error: assignment of read-only variable ‘ptr3’
  // *ptr3 = 7; // assignment of read-only location ‘*(const int*)ptr3’

  // In case of Refernce declaration, the referent should be always an lvalue,
  // can't be 23. int &ref1 = 23;

  /* But if we declare with a const qualifier, it means the ref is holding a
     constant value. In this case, memory will be created for the temporary
     object that holds the value 23, and ref1 will reference this temporary
     object. The scope of the object is scope of ref1. However, no separate
     memory is created specifically for the reference ref1 itself; it just
     points to the memory location of the temporary object created by the
     compiler. */

  const int &ref1 = 23;
  cout << "&ref1 = " << &ref1 << endl;
  return 0;
}
