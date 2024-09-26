#include "Integer.h"
#include <iostream>
#include <string>

using namespace std;

class Employee {
  string name;
  Integer id;

public:
  // Case 1:
  /*
      Employee(const string &n, const Integer &i) : name{n},id{i} {
          cout << "Employee(const string &n, const Integer &i)\n";
      }
  */
  /* The output for eg: 1 is:
  Integer(int) => While passing 100 to Employee() as const Integer &, need to
  convert from int->Integer => Integer(int) is called Integer(const Integer &)
  => By id{i}, this is called. ~Integer() ~Integer()
  */

  // case 2:
  /* Instead of l-value reference, as we know we are passing temporary values,
     we can accept r-value reference arguments */
  /*
      Employee(string &&n, Integer &&i) : name{n},id{i} {
          cout << "Employee(string &&n, Integer &&i)\n";
      }
  After writing the 2nd function which accepts arguments as r-value reference,
  we can see call to that function.

  The output for eg:1 is:
  Integer(int) => While passing 100 to Employee() as r-value ref, need to
  convert from int->Integer => Integer(int) is called Integer(const Integer &)
  => By id(i) Employee(string &&n, Integer &&i) => Move constructor for Employee
  as implemented ~Integer() ~Integer()
  */

  // Case 3:
  /*
      Employee(string &&n, Integer &&i) : name{n},id{move(i)} {
          cout << "Employee(string &&n, Integer &&i)\n";
      }
  */
  /* The output for eg:1 is:
  Integer(int) => While passing 100 to Employee() as r-value ref, need to
  convert from int->Integer => Integer(int) is called Integer(Integer &&) =>
  id{move(i)} Employee(string &&n, Integer &&i) => Move constructor for Employee
  as implemented ~Integer() ~Integer()


  The output for eg:2 is:
  1st argument is l-value reference, and 2nd is r-value reference, and it will
  match with the Employee Copy constructor call:

  Integer(int)
  Integer(const Integer &)
  Employee(const string &n, const Integer &i)
  ~Integer()
  ~Integer()

  So we need to have a combination of Employee(const string &n, Integer &&i),
  like this we should have 4 combinations. As the number of arguments increases,
  we need more combinations.
  */

  // case 4:
  /*
  template <typename T1, typename T2>
  Employee(T1 &&n, T2 &&i) : name{n},id{i} {
          cout << "Employee(string &&n, Integer &&i)\n";
  }
  */

  /* Rules
  If you pass lvalue-ref as argument, it will be treated as l-value ref only
  */

  /* For all the 4 egs, the output is:
  For Employee1: ==>
  Integer(int) => by id{i}
  Employee(string &&n, Integer &&i) => by the employee constructor

  For the 5th eg:

  For Employee5: ==>
  Integer(int)
  Integer(const Integer &)
  Employee(string &&n, Integer &&i)

  We are converting 100 to Integer with Integer(100), so Integer(int) is called.
  Integer(const Integer &) => Copy constructor is called bcz: even though we are
  passing as the r-value reference in Employee, but to id{i}, we are passing the
  name i.e. l-value-ref. So Copy constructor is called.

  So to preserve the type while passing to id{} => we can use
  id{std::forward(i)}
  */

  // case 5:
  template <typename T1, typename T2>
  Employee(T1 &&n, T2 &&i) : name{forward<T1>(n)}, id{forward<T2>(i)} {
    cout << "Employee(string &&n, Integer &&i)\n";
  }
  /*
  For Employee5: ==>
  Integer(int)
  Integer(Integer &&) => Move constructor is called because: forward typecasts i
  to have correct reference by T2 i.e. r-value ref. Employee(string &&n, Integer
  &&i)
  */
};

int main() {

  cout << "For Employee1: ==>\n";

  // Eg-1:
  Employee e1{"Alice", 100};

  cout << "For Employee2: ==>\n";
  // Eg-2:
  string x{"Bob"};
  Employee e2{x, 200};

  // Eg-3:

  cout << "For Employee3: ==>\n";
  int y{3};
  Employee e3{"Cian", y};

  // Eg-4:
  cout << "For Employee4: ==>\n";
  Employee e4{x, y};

  // Eg-5:
  cout << "For Employee5: ==>\n";
  Employee e5{"Alice", Integer(100)};

  return 0;
}
