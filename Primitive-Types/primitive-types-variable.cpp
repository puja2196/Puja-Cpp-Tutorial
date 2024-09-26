#include <iostream>
using namespace std;

int main() {
  /* 1. Scaler Types */

  /* Integer types */
  int i;
  // cout << i; // Some compiler refuses to build because "i" is a local
  // uninitialized variable

  char c = 'a';

  /* Boolean Types */
  bool b = true; // Boolean variables can be initialized with 2 possible values:
                 // true/false

  /* Boolean variables can be initialized to Integer as well */
  bool flag = 0;    // 0 defaults to false
  bool flag1 = 123; // Non-zero value defaults to true, flag1 = true i.e. 1.
  // cout << flag1;

  /* Floating point types */

  float f = 1.234f; // Should be suffixed with "f"
  double d = 1234.456;

  /* Vector types */

  // all arrays are vector types.

  int arr[5];                        // Array declaration without initialization
  int arr_init[5] = {8, 2, 3, 1, 2}; // Array declaration with initialization

  /* C++ 11 Uniform initialization */

  /* Scaler Type */

  int j{10}; // int j = 10;

  int arr_init_1[5]{8, 2, 3, 1, 2}; // int arr_init_1[5] = {8,2,3,1,2};
  cout << arr_init_1[4];
}
