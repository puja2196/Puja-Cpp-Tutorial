#include <iostream>
#include <memory>

using namespace std;

class Free {
public:
  void operator()(int *p) {
    free(p);
    cout << "Free p\n";
  }
};

void MallocFree(int *p) {
  free(p);
  cout << "Free p\n";
}

int main() {
  unique_ptr<int> p{(int *)malloc(4)};
  *p = 100;
  cout << *p << endl;
  /* The above wont work always because Its C-Style m/y allocation i.e malloc,
     so need to call free, But Smart pointers call delete by default */
  /* For specifying the deleter,
     Using Function object: by overloading operator function: we need to specify
     "deleter type" i.e. the Class type: Free and an object of the class in the
     arg list of p Using Function POinter: specify type: void(*)(int*) =>
     function return type(* for function Pointer)(ArgType) and the function name
     in the arglist of p */
  unique_ptr<int, Free> u_p{(int *)malloc(4), Free{}};
  unique_ptr<int, void (*)(int *)> u_q{(int *)malloc(4), MallocFree};

  shared_ptr<int> s_p{(int *)malloc(4), Free{}};
  shared_ptr<int> s_q{(int *)malloc(4), MallocFree};

  return 0;
}
