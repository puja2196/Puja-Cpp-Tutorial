#include <iostream>

using namespace std;

template <int size> void Print() {
  // size++; // error: increment of read-only location ‘size’
  int buffer[size]; // As constexpr => known at compile time, so can allocate an
                    // array
  cout << size << endl;
}

template <typename T> T Sum(T *arr, int size) {
  T sum{};
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

template <typename T, int size> T Sum2(T (&arr)[size]) {
  T sum{};
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

int main() {
  Print<3>();
  /* The non-type template argument should be constant */
  int i = 3;
  // Print<i>(); // the value of ‘i’ is not usable in a constant expression

  Print<sizeof(i)>(); // sizeof(i) known at compile time, so constant
                      // expression.

  int arr[]{3, 4, 1, 2};
  cout << Sum(arr, 4) << endl;

  // int (&ref)[4] = arr; // You can access the array using reference: But need
  // to give correct size: T (&arr)[size]
  cout << Sum2(arr) << endl;

  return 0;
}
