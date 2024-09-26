#include "Integer.h"

Integer Add(const Integer &obj1, const Integer &obj2) {
  Integer res;
  res.set(obj1.get() + obj2.get());
  return res;
}

int main() {
  Integer a(8), b(2);
  a.set(Add(a, b).get());
  /* Outputs for different build and standard:
     1. In C++98: It doesn't have Return-Value Optimization:
  Integer(int)      // Constructor for a (value 8)
  Integer(int)      // Constructor for b (value 2)
  Integer()         // Default constructor for res (inside Add)
  Integer(const Integer &) // Copy constructor for the temporary object returned
  by Add ~Integer()        // Destructor for res (inside Add) ~Integer() //
  Destructor for the temporary object ~Integer()        // Destructor for b
  ~Integer()        // Destructor for a

     2. In C++11 and +:
        1. With RVO:
  Integer(int)
  Integer(int)
  Integer()
  ~Integer()
  ~Integer()
  ~Integer()

        2. Disabling RVO: g++ -fno-elide-constructors
  Integer(int)      // Constructor for a (value 8)
  Integer(int)      // Constructor for b (value 2)
  Integer()         // Default constructor for res (inside Add)
  Integer(const Integer &) // Copy constructor for the temporary object returned
  by Add ~Integer()        // Destructor for res (inside Add) ~Integer() //
  Destructor for the temporary object ~Integer()        // Destructor for b
  ~Integer()        // Destructor for a

       3. Disabling RVO and having move constructors
  Integer(int)
  Integer(int)
  Integer()
  Integer(Integer &&)
  ~Integer()
  ~Integer()
  ~Integer()
  ~Integer()

  While returning the object as a value from Add function, instead of calling
  Copy constructor, Move constructor is called. Deep Copy => obj2 is created and
  obj1's data is copied to obj2. Eg: user defined Copy-constructor Move => obj2
  is created and obj2's data values are copied from obj1 and obj2's pointers are
  pointing to obj1's. Obj1's pointers are made null.
  */
  return 0;
}
