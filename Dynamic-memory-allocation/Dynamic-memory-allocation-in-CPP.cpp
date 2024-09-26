#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int *a = new int;
  *a = 6;
  cout << "*a = " << *a << endl;
  delete a;
  a = nullptr;

  int *b = new int(5);
  cout << "*b = " << *b << endl;
  delete b;
  b = nullptr;

  /* new for array */

  int *p = new int[5]; // allocate array of 5 integers
  for (int i = 0; i < 5; i++) {
    p[i] = i + 1; // Initialtze the array
  }
  delete[] p; // free the memory for array

  int *p2 = new int[4]{3, -1, 6, 5}; // with initializer list
  delete[] p2;

  /* creating strings */
  char *s1 = new char[4];
  strcpy(s1, "C++"); // Last byte is for null terminating character
  cout << s1;
  delete[] s1;

  /* 2D arrays */
  /* Allocate memory for 2x3 array */
  int *ptr1 = new int[3]; // For 1st row
  int *ptr2 = new int[3]; // 2nd row

  int **ptr3 = new int *[2]; // 1-d array of integer pointers
  ptr3[0] = ptr1;
  ptr3[1] = ptr2;

  ptr3[0][1] = 4; // access 0th row's 1st element

  // Deallocate/free the memory in the same order
  delete[] ptr1; // or, delete []ptr3[0];
  delete[] ptr2; // or, delete []ptr3[1];
  delete[] ptr3;

  return 0;
}
