#include <iostream>

class Integer {
  int *p_Int;

public:
  Integer();
  Integer(int);
  Integer(const Integer &obj);
  Integer(Integer &&obj);
  Integer
  operator+(const Integer &) const; // "+" operator => This is const function
                                    // because It wont change the arguments.
  Integer &operator++();   // Pre-Increment operator, As ++ can be applied to
                           // l-value, so it can return reference.
  Integer operator++(int); /* Post Increment operator, int argument is just to
 distinguish between post and pre increment operators. As the temporary object
 is created as a copy and returned and old object remained, so we are returning
 as a value. So return type is "Integer" not "Integer &" */
  bool operator==(const Integer &obj) const; // Equal-to operator
  Integer &operator=(const Integer &obj);    // Assignment Operator

  friend std::istream &operator>>(std::istream &in, Integer &obj);
  void operator()();
  int get() const;
  void set(int);
  ~Integer();
  friend class Printer; // Printer is a friend class of Integer. So Printer can
                        // use Integer's member function.
};

class Printer {};
