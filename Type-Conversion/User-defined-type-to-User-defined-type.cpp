#include "Integer.h"
#include <iostream>

using namespace std;

class Product {
  Integer m_Id;

public:
  Product(const Integer &id) : m_Id(id) {
    cout << "Product(const Integer&)" << endl;
  }
  ~Product() { cout << "~Product()" << endl; }
  const Integer &GetInteger() const { return m_Id; }
  /* Type Conversion Operator Function */
  operator Integer() { return m_Id; }
};

int main() {
  Product p{5};

  Integer i1 = p;
  cout << "i1 = " << i1.get() << endl;
  /* For converting a Product to Integer Object, we need to have a constructor
     in Integer Class. If we dont want to modify the Integer Class, then this
     can be performed in 2 ways :
     1. A member function in Product which returns Integer object
     2. Type conversion function
  */
  // For 1 we need to use:
  Integer i2 = p.GetInteger();
  cout << "i2 = " << i2.get() << endl;

  Integer i3{4};

  /* Left Hand side of any operator should be the operator function type: i.e.
   * Integer */
  // if (i3 == p) cout << "Both are equal\n"; // Works

  // if (p == i2) cout << "Both are equal\n"; // fails
  return 0;
}
