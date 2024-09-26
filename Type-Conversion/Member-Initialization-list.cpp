#include "Integer.h"
#include <iostream>

using namespace std;

class Product {
  Integer m_Id;

public:
  Product(const Integer &id) {
    cout << "Product(const Integer&)" << endl;
    m_Id = id;
  }
  ~Product() { cout << "~Product()" << endl; }
};

class Product2 {
  Integer m_Id;
  int x;

public:
  /* Using Initialization using member-initialization list over Assignment */
  /* We can have any number of elements in the initializer list. Just the order
     should match with the declaration */
  Product2(const Integer &id) : m_Id(id), x(id.get()) {
    cout << "Product2(const Integer&)" << endl;
    // m_Id = id;
  }
  ~Product2() { cout << "~Product2()" << endl; }
};

int main() {
  // Product p(6);
  /* Output:
  Integer(int)
  Integer()
  Product(const Integer&)
  operator=(const Integer &)
  ~Integer()
  ~Product()
  ~Integer()
  */
  /* Product p(6) => Product p(Integer(6)) => By Integer(6), Integer(int) is
     called. Then the Product is invoked with parameterized constructor with
     arg: (Integer). Integer() => This is because we are default constructing
     the Integer object in line 7. Then Product(const Integer&) will be printed
     by Product(const Integer &id). Now we have an assignment in the
     constructor: which is operator=(const Integer &), It is Copy-Assignement
     operator. operator=(const Integer &). */

  Product2 p2(5);
  /* Output:
  Integer(int)
  Integer(const Integer &)
  Product2(const Integer&)
  ~Integer()
  ~Product2()
  ~Integer()
  */
  return 0;
}
