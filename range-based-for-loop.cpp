#include <iostream>

using namespace std;

int main() {
  int arr[] = {2, 3, 1, 5, 7};
  cout << "Printing array element===>\n";
  for (int x : arr) {
    cout << x << " ";
  }
  cout << endl;

  // we can make the type of x as "auto": This will work
  cout << "Printing array element===>\n";
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;

  /* Both the previous approaches will create a copy of the array element in
     each iteration Avoid this using reference */
  cout << "Printing array element===>\n";
  for (auto &x : arr) {
    cout << x << " ";
  }
  cout << endl;

  /* Using auto &, may change the array element accidentally, Given example
   * below */
  int arr2[] = {3, 5, 1, 7, 8};
  for (auto &x : arr2) {
    x = 4;
  }
  cout << "Printing array2 element after changing===>\n";
  for (auto &x : arr2) {
    cout << x << " ";
  }
  cout << endl;

  /* Best practice to use "const auto & x" */
  for (const auto &x : arr) {
    // x = 4; // Compiler error: assignment of read-only reference ‘x’
  }

  cout << "Printing array element===>\n";
  for (const auto &x : arr) {
    cout << x << " ";
  }
  cout << endl;

  /* Iterate over an initializer list */
  cout << "Printing element of initializer list===>\n";
  for (const auto &x : {1, 2, 3, 4}) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
