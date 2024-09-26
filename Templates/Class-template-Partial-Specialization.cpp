#include <iostream>

using namespace std;

template <typename T, int cols> class Printer {
  T *m_Data;

public:
  Printer(T *data) : m_Data{data} {}
  void Print() {
    cout << "Cols = " << cols << endl;
    cout << "{" << *m_Data << "}" << endl;
  }
  T *Getdata() { return m_Data; }
};

/* we may need to do some specilization when the cols=80 */
template <typename T> class Printer<T, 80> {
  T *m_Data;

public:
  Printer(T *data) : m_Data{data} {}
  void Print() {
    cout << "Using 80 Cols Printer :" << endl; // Change the message
    cout << "{" << *m_Data << "}" << endl;
  }
  T *Getdata() { return m_Data; }
};

int main() {

  int data = 30;
  Printer<int, 40> p{&data};
  p.Print();

  Printer<int, 80> p1{&data};
  p1.Print();
  return 0;
}
