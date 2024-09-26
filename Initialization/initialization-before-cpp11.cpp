/* C++98 has different ways to initialize types.
 * 1. For scaler types:
 *    i. Using "=" operator: int a = 5;
 *    ii. Using "()": Myclass obj = Myclass();
 *        It is commonly used to initialize objects of class types using default
 * constructors.
 * 2. Vector types: Using "{}" operator:
 * int arr[5] = {2, 4, 5, -1, 0}; ==> for vector types
 */

#include <iostream>

using namespace std;

int main() {
  /* whenever using a "=" for assigning, is called as "Copy Initialization" */
  /* Primitive type */
  int a1;      // UnInitialized Variable
  int a2 = 10; // Initialized using "=" => Copy Initialization
  int a3(9);   // Direct Initialization

  /* User defined type */
  std::string s1; // Uninitialized variable => default constructor is called.
  std::string s2("c++"); // Direct Initialization

  /* Array types */
  char d1[8];          // Unitialized
  char d2[8] = {'\0'}; // With null characters => Copy Initialization
  char d3[8] = {'a', 'b', 'c',
                'd'};    // Aggregate Initialization => Copy Initialization
  char d4[8] = {"abcd"}; // Initialize to a string => Copy Initialization
  return 0;
}
