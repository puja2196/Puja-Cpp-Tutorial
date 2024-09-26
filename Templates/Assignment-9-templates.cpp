#include <iostream>
#include <string>
using namespace std;

class Employee {
  string name;
  int id;
  float salary;

public:
  Employee(const string &n, const int &i, const float &f)
      : name{n}, id{i}, salary{f} {
    cout << "Employee()\n";
  }
};

class Contact {
  string name;
  int phone;
  string address;
  string email;

public:
  Contact(const string &n, const int &i, const string &a, const string &b)
      : name{n}, phone{i}, address{a}, email{b} {
    cout << "Contact()\n";
  }
};

template <typename T, typename... Params> T *CreateObject(Params &&...args) {
  return new T{forward<Params>(args)...};
}

int main() {
  int *p1 = CreateObject<int>(5);

  string *s = CreateObject<string>(); // Default construction

  Employee *emp = CreateObject<Employee>("Bob", // Name
                                         101,   // Id
                                         1000); // Salary

  Contact *p = CreateObject<Contact>("Joey",                // Name
                                     987654321,             // Phone number
                                     "Boulevard Road, Sgr", // Address
                                     "joey@poash.com");     // Email
  return 0;
}
