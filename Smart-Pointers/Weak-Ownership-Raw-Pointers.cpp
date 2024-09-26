#include <iostream>

using namespace std;

class Printer {
  int *m_p;

public:
  void Set(int *p) { m_p = p; }
  void Print() { cout << "Value is " << *m_p << endl; }
};

int main() {
  Printer prn;
  cout << "Enter the number: ";
  int num;
  cin >> num;

  int *p = new int{num};
  prn.Set(p);
  prn.Print();
  delete p;

  int *q = new int{num};
  prn.Set(q);
  /* Complex Code */
  if (*q > 10) {
    delete q;
    q = nullptr; // To make sure we don't delete it again
  }
  /* If I provide a number > 10 say 15, q gets deleted, so m_p is pointing to
     the memory which is deleted already, Program will show garbage value or
     zero in that case */
  prn.Print();
  /* So How to make Print know about the underlying pointer so that it can
   * check? */
  /* Very hard to do with Raw pointers, so use Smart Pointers */
  delete q;
  return 0;
}
