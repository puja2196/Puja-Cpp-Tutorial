/*
 * C++11 has introduced uniform Initialization using "{}" for scaler and vector
 * both types.
 *
 */

#include <iostream>

using namespace std;

int main() {
  int b1{};  // Value Initialization: initialize to its default value: for all
             // types, it is "0".
  int b2{5}; // Direct Initialization

  char arr1[3]{};           // array element initialize to default value.
  int arr2[4]{2, 3, -1, 6}; // Direct Initialization
  char arr3[8]{"Hello"};    // Direct Initialization

  cout << "b1 =" << b1;
  cout << "\narr2[2] =" << arr2[2];

  /* Heap Object Initialization */
  int *p1 = new int{}; // Value Initialization

  char *p2 = new char[8]{};        // Value Initialization
  char *p3 = new char[8]{"Hello"}; // Pass value dynamically

  float f{};
  // int i{f}; ==> warning: narrowing conversion of ‘f’ from ‘float’ to ‘int’
  // [-Wnarrowing]

  return 0;
}

/* Different Types of Initialization
   1. Value Initialization: T obj{};
   2. Direct Initialization: T obj{val}; ==> Usually done for user-defined types
                             This ensures type-check of "val" with T while
   initializing and reports error/warning if any
   3. Copy Initialization: T obj = val; ==> Usually done for primitive types
*/
