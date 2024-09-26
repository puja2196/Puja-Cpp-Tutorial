#include <iostream>

using namespace std;

union Test {
  /* By default all the union data members and functions are public */
  int x;
  char ch;
  /* All the data members share a single space */
  /* In the constructor of Union you can't initialize multiple members. So the
     follwing yields an error Test(): x{1}, ch{'a'} { cout <<
     __PRETTY_FUNCTION__ << endl;
      }
  */
  Test() : x{500} { cout << __PRETTY_FUNCTION__ << endl; }

  ~Test() { cout << __PRETTY_FUNCTION__ << endl; }
};

int main() {
  Test t;
  cout << "t.x = " << t.x
       << endl; // as x is initialized, so it is an active member

  t.ch = 'a'; // Making ch as active member
  cout << "t.x = " << t.x
       << endl; // Accessing non-active member, so garbage value
                /* Size of the union is equal to its largest data member size */
  cout << "Size of the union is: " << sizeof(t) << endl;
  return 0;
}
