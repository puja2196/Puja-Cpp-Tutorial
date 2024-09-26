#include <iostream>
#include <vector>

using namespace std;

template <typename T> class Printer {
  T *m_Data;

public:
  Printer(T *data) : m_Data{data} {}
  void Print() { cout << "{" << *m_Data << "}" << endl; }
  T *Getdata() { return m_Data; }
};

// Explicit Class specialization for char* type
template <> class Printer<char *> {
  char *m_Data;

public:
  Printer(char *data) : m_Data{data} {}
  void Print() { cout << "{" << m_Data << "}" << endl; }
  char *Getdata() { return m_Data; }
};

// Explicit specialization of Print function for vector type
template <> void Printer<vector<int>>::Print() {
  cout << "\n{";
  for (auto &x : *m_Data) {
    cout << x << " ";
  }
  cout << "}" << endl;
}

template <> void Printer<vector<vector<int>>>::Print() {
  cout << "\n{";
  for (auto &x : *m_Data) {
    cout << "\n{";
    for (auto &y : x) {
      cout << y << " ";
    }
    cout << "}" << endl;
  }
  cout << "}" << endl;
}

int main() {

  int i = 5;
  float f = 6.4f;
  Printer<int> p{&i};
  p.Print();

  Printer<float> p2{&f};
  p2.Print();

  char *c1{"Hello World"};
  /* Printer<char*> p3{c1}; => wont work, bcz c1 is char* so while passing to
  p3{char*} => Printer(T **)
  => so error */
  Printer<char *> p3{c1};
  p3.Print();

  // char* pdata = p3.Getdata(); // error: cannot convert ‘char**’ to ‘char*’ in
  // initialization
  /* Using this implementation for char* is very errorneus */
  char *pdata = p3.Getdata();

  /* For char*, none of the functions of Printer was working, so needed Explicit
     specialization for the whole class */
  vector<int> v{1, 2, 8, 4, 6};
  Printer<vector<int>> p4{&v};
  p4.Print(); // Error for this function as << is not overloaded for vector
              // object. So we can do explicit specialization of this function
              // for vector type data.

  vector<int> v1{1, 2, 3};
  vector<int> v2{4, 5, 6};

  vector<vector<int>> mv{};
  mv.push_back(v1);
  mv.push_back(v2);

  Printer<vector<vector<int>>> p5{&mv};
  p5.Print();
  /*
  //Main vector (vector<vector<int>>)
  {
      {1,2,3},    //first element vector<int>
      {4,5,6}     //second element vector<int>
  }
  */
  return 0;
}
