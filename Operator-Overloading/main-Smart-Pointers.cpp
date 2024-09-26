#include "Integer.h"
#include <iostream>
using namespace std;

/* This function allocating memory in heap, which is not deleted => Memory Leak
 */
void CreateInteger(int a) {
  Integer *i1 = new Integer;
  i1->set(a);
  cout << "i1 = " << i1->get() << endl;
  // delete i1; //=> Solution But sometimes programmer can forget it.
}

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

void CreateInteger2(int a) {
  Intptr i1 = new Integer;
  /* This Intptr is a  smart pointer and acts as local object.
     If you build and run this, we can see: object is created and destroyed.
     But set() function is not a member of i1, so i1->set(a) can't be used,
     We need to overload "->" in such a way that, Intptr works as a pointer to
     an Integer object and we can use all the Integer class's functions
     Here all i1-> is treated as (i1.m_p)-> */
  i1->set(a);
  cout << "i1 = " << i1->get() << endl;

  Intptr i2 = new Integer;
  (*i2).set(a);
  cout << "i2 = " << (*i2).get() << endl;
}

int main() {
  CreateInteger2(5);
  return 0;
}
