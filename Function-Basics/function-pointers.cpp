#include <iostream>

using namespace std;

int Add(int x, int y) { return (x + y); }

void Print(int x, char ch) {
  for (int i = 0; i < x; i++) {
    cout << ch;
  }
  cout << endl;
}

int main() {
  // Declaration of Function pointer
  int (*funcPtr1)(int, int) = &Add;
  void (*funcPtr2)(int, char) =
      &Print; // void (*funcPtr2)(int,char) = Print; ==> also will work.

  // Normal Function call
  Print(5, '*');

  // Calling through function pointer
  (*funcPtr2)(6, '$');
  funcPtr2(7, '@');
  return 0;
}
