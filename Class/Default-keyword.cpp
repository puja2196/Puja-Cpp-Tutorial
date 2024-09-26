#include <iostream>

using namespace std;

class Integer {
  /*
      int m_value;
  public:
      // Default Constructor
      Integer(){
          m_value = 0;
      }
      Integer(int value) {
          m_value = value;
      }
  */
  /*Here the default constructor not doing anything except initializing m_value
    as 0. We can do this using Initializer itself and also remove the default
    constructor definition */
  int m_value{0};

public:
  Integer(int value) { m_value = value; }
  /* As we have the user-defined parameterized constructor,
     Compiler won't generate the default construor by default
     To generate this, use the below */
  Integer() = default;
  /* Now compiler will generate the default constructor by seeing the keyword */
  /* We can use default for compiler synthesized function like copy constructor,
     default constructor, destructor */

  /* Ask compiler to create default Copy constructor */
  Integer(const Integer &obj) = default;
};

int main() {
  Integer i1;
  Integer i2(3);
  return 0;
}
