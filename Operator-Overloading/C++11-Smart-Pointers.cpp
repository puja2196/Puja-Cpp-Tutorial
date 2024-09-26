#include "Integer.h"
#include <iostream>
#include <memory> // Smart pointers are defined in memory headerfile.

using namespace std;

class Intptr {
  Integer *m_p;

public:
  Intptr(Integer *p) : m_p(p) {}
  ~Intptr() { delete m_p; }
  /* Overloading -> operator */
  Integer *operator->() { return m_p; }

  /* Overloading * operator */
  Integer &operator*() { return *m_p; }
};

void Process(unique_ptr<Integer> ptr) {
  /* here ptr is passed by value, so object i1 should be copied, But as
     i1 is unique_ptr, can not be copied, the ownership of the resources
     only can be moved to ptr from i1, so use std::move() while calling */
  cout << "From Process with unique_ptr: " << ptr->get() << endl;
}

void Process(shared_ptr<Integer> ptr) {
  cout << "From Process with shared_ptr: " << ptr->get() << endl;
}

void CreateInteger(int a) {

  unique_ptr<Integer> i1(new Integer);
  /* unique_ptr is used when you dont want to share the underlying resource
     You can't create the copy of unique_ptr
      auto i2{i1}; => gives error */
  i1->set(a);
  cout << "i1 = " << i1->get() << endl;
  // Process(i1); // Error: explanation given in the "Process" definition
  Process(std::move(i1)); // Specify move so that its clear to the compiler that
                          // we want to move
  // cout << "i1 = " << i1->get() <<endl; // Segfault as we moved the resources
  // from i1 to ptr.

  /* If you want to share the underlying resources, then use shared_ptr */
  shared_ptr<Integer> i2(new Integer);
  Process(i2);
}

int main() {
  CreateInteger(5);
  return 0;
}
