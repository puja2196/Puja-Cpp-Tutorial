#include <cstring>
#include <iostream>

using namespace std;
/*
int Max(int i, int j) {
    return (i>j)?i:j;
}

float Max(float i, float j) {
    return (i>j)?i:j;
}

Instead of writing above 2 functions, can write a generic function:
This is called Function Template bcz it always accepts template type argument
Properties:
1. It always begins with "template" keyword.
2. Each template type argument(in the <> bracket) is a type-name.
3. We can have multiple typename.
4. typename can be a return type.
*/

// Primary template:
template <typename T> T Max(T i, T j) { return (i > j) ? i : j; }

// case 3: Using Explicit Instantiation
template char Max(char, char);

// case 4: using Explicit Specialization

template <> const char *Max(const char *x, const char *y) {
  return strcmp(x, y) > 0 ? x : y;
}

int main() {

  auto max1 = Max(12, 23);
  cout << max1 << endl;

  auto max2 = Max(1.62f, -2.3f);
  cout << max2 << endl;

  /* Suppose we call with (int, float) => can't be deduced to Max(T,T) so
   * compiler error */
  // Max(12, 23.3f); // error: no matching function for call to ‘Max(int,
  // float)’

  // To make this work:
  // case 1:
  Max(static_cast<float>(12), 23.f); // Acts as float
  Max<double>(12, 23.3f);            // Acts as double

  /* The template instantiation happens after type deduction step
  It can happen any way:
     1. Function Template is invoked like above
     2. taking address of a function template
     3. Using Explicit Instantiation
     4. Using Explicit Specialization
   */

  // Case 2: taking address of a function template
  int (*pfn)(int, int) = Max;

  /* Suppose we dont have case4  => Max(b,a) => Output is A, bcz it compares
     address and return A. So for Explicit specialization, we need to have case
     4 */
  const char *b{"B"};
  const char *a{"A"};

  cout << Max(b, a) << endl;
  return 0;
}
