#include <iostream>

using namespace std;

#include <iostream>

struct A {
  // Constructor
  A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  // Destructor
  ~A() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  // Copy Constructor
  A(const A &other) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  // Copy Assignment Operator
  A &operator=(const A &other) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (this == &other)
      return *this; // Handle self-assignment
    return *this;
  }

  // Move Constructor
  A(A &&other) noexcept { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  // Move Assignment Operator
  A &operator=(A &&other) noexcept {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (this == &other)
      return *this; // Handle self-assignment
    return *this;
  }
};

#include <iostream>

struct B {
  // Constructor
  B() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  // Destructor
  ~B() { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  // Copy Constructor
  B(const B &other) { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  // Copy Assignment Operator
  B &operator=(const B &other) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (this == &other)
      return *this; // Handle self-assignment
    return *this;
  }

  // Move Constructor
  B(B &&other) noexcept { std::cout << __PRETTY_FUNCTION__ << std::endl; }

  // Move Assignment Operator
  B &operator=(B &&other) noexcept {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    if (this == &other)
      return *this; // Handle self-assignment
    return *this;
  }
};

/* Union containing User-defined objects */
union UDT {
  A a;
  B b;
  /* As A and B has User-defined constructors and destructors, so UDT also
   * should have */
  UDT() {}
  ~UDT() {}
};

int main() {
  UDT udt; /* Here even though udt object is created, A and B objects are not
              created, In this case M/y allocated for A or B but not
              initialized, so need to initialize manually */
  new (&udt.a) A{}; // Initialize udt.a m/y for new object of type A
  udt.a.~A();       // destroy the object
}
