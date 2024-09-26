#include "Integer.h"
#include <iostream>

using namespace std;

class Number {
  Integer m_value{}; /* Number has compiler-generated copy and move constructor
                        which will invoke the Integer class's user-defined copy
                        and move constructor*/
public:
  Number(int value) : m_value{0} {}

  /* Case-1:
  If Number has user-defined copy constructor, it wont generate its own move
  constructor, move assignment operator, as it has copy constructor,  compiler
  wont generate copy constructor but it will generate copy assignment operator
*/

  /*
      Number(const Number &obj):m_value{obj.m_value} {
      }
  */

  /* Output:
  Number n1{1}; => Integer(int) It will call Integer(int) constructor while
  calling Number(int) constructor auto n2{n1}; => Integer(const Integer &) It
  will call Number class's constructor which eventually call Integer class's
  constructor n2 = n1; => operator=(const Integer &) => As Number class doesnt
  have copy assignment operator, it will generate one and will call Integer
  class's user-defined copy assignment operator auto n3{CreateNumber(3)}; =>
  Integer(int) => called while creating Number object inside the "CreateNumber"
  function Integer(const Integer &) => while returning from the function,
  calling Number's user-defined copy constructor as existed and eventually
  Integer's copy constructor ~Integer()

  n2 = CreateNumber(5); =>
  Integer(int) => called while creating Number object inside the "CreateNumber"
  function. Integer(const Integer &) => while returning from the function,
  calling Number's user-defined copy constructor as existed and eventually
  Integer's copy constructor ~Integer() operator=(const Integer &) => for the
  assignment, it will invoke compiler generated Number's Copy Assignment
  operator which calls Integer's Copy Assignment Operator ~Integer() ~Integer()
  ~Integer()
  ~Integer()
  */

  /* Case-2:
  If you have a user-defined Destructor, it will also block constructing all the
  move operations: move constructor, move assignment operator.
  */

  /*
      ~Number(){
      }
  */

  /*
  Same output as Case 1:
  Integer(int)
  Integer(const Integer &)
  operator=(const Integer &)
  Integer(int)
  Integer(const Integer &)
  ~Integer()
  Integer(int)
  Integer(const Integer &)
  ~Integer()
  operator=(const Integer &)
  ~Integer()
  ~Integer()
  ~Integer()
  ~Integer()
  */

  /* Case 3:
  If you have a user-defined move constructor, it will delete all the copy and
  move operations (copy constructor, copy assignment operator, move constructor,
  move assignment operator).
  */
  /*
      Number(Number &&obj) : m_value{std::move(obj.m_value)} {
      }
  */
  /*
  Output:
  1. auto n2{n1}; => Error as Copy constructor is not defined and compiler
  generated copy constructor deleted.
  2. n2 = n1; => Error as Copy assignment operator is not defined and compiler
  generated copy assignment operator deleted.
  3. n2 = CreateNumber(5); => Error as Move assignment operator is not defined
  and compiler generated Move assignment operator deleted and its needed in the
  statement
  */

  /* Case 4:
  If you have a user-defined move constructor and you want move assignment
  operator also to work:
  */
  /*
      Number(Number &&obj) : m_value{std::move(obj.m_value)} {
      }
      Number & operator=(Number &&obj) = default;
  */
  /* Output:
  1. auto n2{n1}; => Error as Copy constructor is not defined and compiler
  generated copy constructor deleted.
  2. n2 = n1; => Error as Copy assignment operator is not defined and compiler
  generated copy assignment operator deleted. But n2 = CreateNumber(5); is
  working because we are using the default move assignment operator.
  */

  /* Case 5:
  If you have a move constructor and move assignment operator defined as
  default: It is using the compiler generated default move constructor and move
  assignment operator but it will block the copy operations */

  /*
      Number(Number &&obj) = default;
      Number & operator=(Number &&obj) = default;
  */

  /* Same output as Case 4 */

  /* Case 6:
  If you have a move constructor, move assignment operator, copy constructor
  defined as default: It is using the compiler generated default move
  constructor, move assignment operator and copy constructor but it will block
  the copy assignment operator */

  /*
      Number(Number &&obj) = default;
      Number & operator=(Number &&obj) = default;
      Number(const Number &obj) = default;
  */

  /* Output:
  1. n2 = n1; => Error as Copy assignment operator is not defined and compiler
  generated copy assignment operator deleted. Others are working now.
  */

  /* Case 7:
  If you have a move constructor, move assignment operator, copy constructor and
  copy assignment operator defined as default: It is using the compiler
  generated default move constructor, move assignment operator, copy constructor
  and copy assignment operator but it will block the other copy operations */
  Number(Number &&obj) = default;
  Number &operator=(Number &&obj) = default;
  Number(const Number &obj) = default;
  Number &operator=(const Number &obj) = default;

  /* Output same as case 1 now */
};

Number CreateNumber(int num) {
  Number n1{num};
  return n1;
}

int main() {
  Number n1{1}; // It will call Integer(int) constructor while calling
                // Number(int) constructor: Integer(int)
  auto n2{n1}; // As Number class doesnt have copy constructor, it will generate
               // one and will call Integer class's user-defined copy
               // constructor : Integer(const Integer &)
  n2 = n1;     // As Number class doesnt have copy assignment operator, it will
               // generate one and will call Integer class's user-defined copy
               // assignment operator : operator=(const Integer &)

  auto n3{CreateNumber(3)};
  /* Without RVO and with Move constructor:
     Here temporary object of Number which is invoking Interger(int) constructor
     as well is created and while returning, Compiler will generate Number's
     Move constructor and invokes Integer's move constructor from there.
     Integer(int) => called while creating Number object inside the
     "CreateNumber" function. Integer(Integer &&) => While returning it will use
     Move constructor. ~Integer() => After returning destroyed the object.

     With RVO:
     Integer(int)
  */
  n2 = CreateNumber(5);
  /* Without RVO and implementing copy and move constructor and assignment
     operator Output: Integer(int) => called while creating Number object inside
     the "CreateNumber" function. Integer(Integer &&) => While returning it will
     use Move constructor. So Compiler generated "Number" class's move
     constructor will call Integer's Move Constructor. ~Integer() => destroy the
     object while returning operator=(Integer &&) => Now for the assignment
     operator, as Number doesnt have its user-defined move assignment operator,
     it will invoke Integer's move assignment operator from Number's compiler
     generated move assignment operator.

     With RVO:
     Integer(int) => called while creating Number object inside the
     "CreateNumber" function. operator=(Integer &&) => Invoke Integer's move
     assignment operator from Number's compiler generated move assignment
     operator.
  */

  return 0;
}
