#include <iostream>

using namespace std;

class Integer {
  int m_value{0};

public:
  Integer() = default;
  Integer(int value) { m_value = value; }
  /* If you dont want the default copy constructor,
     ask compiler to not create Copy constructor */
  Integer(const Integer &obj) = delete;
  /* You can use delete with any function */
  void SetValue(int value) { m_value = value; }
  void SetValue(float) = delete;
};

int main() {
  Integer i1(3);
  // Integer i2(i1); // Leads to error because default copy constructor is
  // deleted and no user defined copy constructor
  i1.SetValue(5);
  i1.SetValue(
      3.4f); /* Even though SetValue only accepts "int", float is passed and
                typecasted. No error or warning, So to avoid this use the
                "delete" for SetValue with argument float type */
  /* Now we will get error as : we used the deleted function */
  return 0;
}
