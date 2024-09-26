#include <iostream>
#include <memory>

using namespace std;

class Printer {
  weak_ptr<int> m_p{};

public:
  void Set(weak_ptr<int> p) { m_p = p; }
  void Print() {
    if (m_p.expired()) { // Reference count of underlying shared pointer is 0
      cout << "Value is no longer available\n";
      return;
    }
    /* Accessing the underlying shared pointers */
    auto sp = m_p.lock();
    cout << "Value is " << *sp << endl;
    cout << "Reference Count of m_p is: " << sp.use_count() << endl;
  }
};

int main() {
  Printer prn;
  cout << "Enter the number: ";
  int num;
  cin >> num;

  shared_ptr<int> q{new int{num}};
  prn.Set(q);
  /* Complex Code */
  if (*q > 10) {
    q = nullptr; // To decrese the reference count
  }
  prn.Print();
  return 0;
}