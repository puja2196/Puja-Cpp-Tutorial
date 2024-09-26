#include "Integer.h"
#include <iostream>

using namespace std;

ostream &operator<<(ostream &out, const Integer &obj) {
  out << obj.get();
  return out;
}

template <typename T> void Print(initializer_list<T> args) {
  for (const auto &x : args) {
    cout << x << " ";
  }
}

void Print2() { cout << endl; }

// template parameter pack => typename... means lists of unknown typenames and
// Params is the name for the template parameter pack
template <typename T, typename... Params>
// function parameter pack
void Print2(T a, Params... args) {
  cout << a;
  // sizeof... is the variadic sizeof operator to check the sizes of variadic
  // template
  if (sizeof...(args) > 0) {
    cout << ", ";
  }
  Print2(args...);
}

/* As we are passing the parameters as copy, for user-defined type it will take
   more space, so pass by reference */

void Print3() { cout << endl; }

template <typename T, typename... Params>
void Print3(const T &a, const Params &...args) {
  cout << a;
  if (sizeof...(args) > 0) {
    cout << ", ";
  }
  Print3(args...);
}

void Print4() { cout << endl; }

template <typename T, typename... Params> void Print4(T &&a, Params &&...args) {
  cout << a;
  if (sizeof...(args) > 0) {
    cout << ", ";
  }
  Print4(forward<Params>(args)...);
}

int main() {

  Print({1, 2, 3, 4});
  cout << endl;

  Print({1.0f, 2.1f, 3.4f, 5.0f});
  cout << endl;

  // Print({1, 2, 3, 4.0f}); // Not possible because: initializer_list should
  // have same type of elements.
  Print2(1, 2, "Max", 4.5f); // Works
  Print3(1, 2, "Max", 4.5f); // Works

  Print3(1, 2,
         Integer{2}); // Even though we are passing as r-value reference as
                      // Integer{2}, i.e. considered as l-value reference.
  Print4(1, 3, Integer{2}, "Puja", 2.3f);

  return 0;
}
