#include <iostream>

using namespace std;

/* "add" is defined in another program, and to use
 * it in this program, declaration is needed. */

int add(int, int);

/* we may need to declare so many functions to use them in this
 * file, so to avoid redundant work, we make those declarations
 * to be avaliable in a header file and include that header files
 * in this file */

int main() {
  int sum = add(1, 2);
  cout << sum;
  return 0;
}
