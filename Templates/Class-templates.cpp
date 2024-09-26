#include <iostream>

using namespace std;

class Stack {
  int m_Buffer[512];
  int m_Top{-1};

public:
  void Push(int x) { m_Buffer[++m_Top] = x; }
  void Pop() { --m_Top; }
  int Top() const { return m_Buffer[m_Top]; }
  bool Isempty() { return (m_Top == -1); }
};
/* The above class will work only for int type, so we need a class template for
   other types */

template <typename T> class Stack2 {
  T m_Buffer[512];
  int m_Top{-1};

public:
  void Push(const T &x) { m_Buffer[++m_Top] = x; }
  void Pop() { --m_Top; }
  const T &Top() const { return m_Buffer[m_Top]; }
  bool Isempty() { return (m_Top == -1); }
};

/* Class template can accept non-type template argument, that becomes a
 * compile-time constant */
template <typename T, int size> class Stack3 {
  T m_Buffer[size];
  int m_Top{-1};

public:
  Stack3() = default;
  Stack3(const Stack3 &obj) {
    m_Top = obj.m_Top;
    for (int i = 0; i <= m_Top; i++) {
      m_Buffer[i] = obj.m_Buffer[i];
    }
  }

  void Push(const T &x) { m_Buffer[++m_Top] = x; }

  void Pop(); // declare here, def moved outside
              /*
                  {
                      --m_Top;
                  }
              */
  const T &Top() const { return m_Buffer[m_Top]; }
  bool Isempty() { return (m_Top == -1); }
  static Stack3 Create();
  /*
      {
          return Stack3<T,size>{};
      }
  */
};

/*To define some of the func say Pop() outside the class */
// template declaration
template <typename T, int size>
// return_type Class_name<Types>::func_name(arg) {...}
void Stack3<T, size>::Pop() {
  --m_Top;
}

template <typename T, int size>
Stack3<T, size>
Stack3<T, size>::Create() { // Stack3 is outside the class, so need long hand
                            // notation "Stack3<T,size>"
  return Stack3<T, size>{};
}

int main() {

  Stack s;
  s.Push(8);
  s.Push(3);
  s.Push(2);
  s.Push(10);

  cout << "s ==>\n";
  while (!s.Isempty()) {
    cout << s.Top() << endl;
    s.Pop();
  }

  Stack2<int> s1;
  s1.Push(8);
  s1.Push(3);
  s1.Push(2);
  s1.Push(10);

  cout << "s1 ==>\n";
  while (!s1.Isempty()) {
    cout << s1.Top() << endl;
    s1.Pop();
  }

  /* Stack2 can accept float type also now */
  Stack2<float> s2;
  s2.Push(1.2f);
  s2.Push(2.1f);

  cout << "s2 ==>\n";
  while (!s2.Isempty()) {
    cout << s2.Top() << endl;
    s2.Pop();
  }

  /* Template with 2 template args */
  Stack3<float, 10> s3;
  s3.Push(1.2f);
  s3.Push(2.1f);

  auto s5{s3}; // To  test the copy constructor
  cout << "s3 ==>\n";
  while (!s3.Isempty()) {
    cout << s3.Top() << endl;
    s3.Pop();
  }

  // Using the factory method to create Stack3 object
  Stack3<int, 10> s4 = Stack3<int, 10>::Create();
  // Stack3<int, 10> s4 = Stack3<int, 9>::Create(); // Class are of different
  // type as size is different, so error

  cout << "s5 ==>\n";
  while (!s5.Isempty()) {
    cout << s5.Top() << endl;
    s5.Pop();
  }

  return 0;
}
