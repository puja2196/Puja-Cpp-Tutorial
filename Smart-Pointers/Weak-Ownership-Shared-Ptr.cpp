#include <iostream>
#include <memory>

using namespace std;

class Printer {
  shared_ptr<int> m_p{};

public:
  void Set(shared_ptr<int> p) { m_p = p; }
  void Print() {
    cout << "Reference Count of m_p is: " << m_p.use_count() << endl;
    cout << "Value is " << *m_p << endl;
  }
};

int main() {
  Printer prn;
  cout << "Enter the number: ";
  int num;
  cin >> num;

  shared_ptr<int> p{new int{num}};
  prn.Set(p);
  prn.Print();
  p.reset(); // or, p = nullptr to decrease the reference count

  shared_ptr<int> q{new int{num}};
  prn.Set(q);
  /* Complex Code */
  if (*q > 10) {
    q = nullptr; // To decrese the reference count
  }
  /* If I provide a number > 10 say 15, q gets deleted, so m_p is pointing to
     the memory which is deleted already, Program will show garbage value or
     zero in that case */
  prn.Print();
  /* So How to make Print know about the underlying pointer so that it can
   * check? */
  /* Very hard to do with Raw pointers, so use Smart Pointers
     In Print function, now a q is a shared pointer, we can check the reference
  count and then only print
  1. If we pass "q" in Set Function by value, then one copy will be created, so
  the reference count is 3, as 1. q-> new int{num}, 2. q's copy is created, 3.
  m_p->q if num < 10 and ref count is 2 if num > 10 as we are doing "q =
  nullptr"
  2. If we pass "q" in Set Function by reference, then no copy will be created,
  so the reference count is 2, as 1. q-> new int{num}, 2. m_p->q if num < 10 and
  ref count is 1 if num > 10 as we are doing "q = nullptr"

  */
  return 0;
}
