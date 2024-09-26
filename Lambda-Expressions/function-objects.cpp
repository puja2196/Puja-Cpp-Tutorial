#include <iostream>

using namespace std;

/*
using Comparator = bool(*)(int,int); // This is just a type-alias

template<typename T, int size>
void Sort(T (&arr)[size], Comparator comp) {
    for (int i=0;i<size-1;i++) {
        for (int j=i+1;j<=size-1;j++) {
            if (comp(arr[i],arr[j])) {
                T temp = move(arr[i]);
                arr[i] = move(arr[j]);
                arr[j] = move(temp);
            }
        }
    }
}
*/

// For Ascending Order
bool Comp1(int x, int y) { return (x > y); }

// For Descending Order
bool Comp2(int x, int y) { return (x < y); }

/* Function object is an object of struct/class that has a function call
 * operator overloaded. Eg */
struct Comp {
  bool operator()(int x, int y) { return (x > y); }
};

// Writing the Sort function to use function-object
template <typename T, int size, typename Comparator>
void Sort(T (&arr)[size], Comparator comp) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j <= size - 1; j++) {
      if (comp(arr[i], arr[j])) {
        T temp = move(arr[i]);
        arr[i] = move(arr[j]);
        arr[j] = move(temp);
      }
    }
  }
}

int main() {
  Comp1(3, 5); // Global Function Call
  Comp cm1;
  cm1(2, 1); // cm1.operator()(2,1) => Member function call

  int arr[]{1, 3, 2, 6, 4};
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;
  Sort(arr, Comp1);
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;

  int arr2[]{2, 1, 5, 8, 3};
  for (auto x : arr2) {
    cout << x << " ";
  }
  cout << endl;

  Sort(arr2, Comp2);
  for (auto x : arr2) {
    cout << x << " ";
  }
  cout << endl;

  // Callback through Function Object
  Sort(arr2, cm1);
  for (auto x : arr2) {
    cout << x << " ";
  }
  cout << endl;

  /* Difference between Function Pointer and Function Object:
     Function Pointer                                    Function Object
  1. Dynamic                                             1. Static in nature
  2. In compile time, we only know the function Address  2. In compile time, we
  know which function is called
  3. Can't do optimization like inlining                 3. Can do inlining as
  function is known at compile time
  4. Can't store state as global function                4. Can store state
  between different invokations
  5. Slow                                                5. Fast
  */
  return 0;
}
