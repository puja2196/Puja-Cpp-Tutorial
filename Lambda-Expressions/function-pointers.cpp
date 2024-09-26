#include <iostream>

using namespace std;

template <typename T, int size> void Sort(T (&arr)[size]) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j <= size - 1; j++) {
      if (arr[i] > arr[j]) {
        T temp = move(arr[i]);
        arr[i] = move(arr[j]);
        arr[j] = move(temp);
      }
    }
  }
}
/* For descending order and strings need to specialize the function,
   actually not the whole function, but the condition, so we can use
   comparator i.e. a function pointer to dynamically decide based on the
   input which condition to use to compare */

using Comparator = bool (*)(int, int); // This is just a type-alias

template <typename T, int size> void Sort2(T (&arr)[size], Comparator comp) {
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

// For Ascending Order
bool Comp1(int x, int y) { return (x > y); }

// For Descending Order
bool Comp2(int x, int y) { return (x < y); }

int main() {

  int arr[]{1, 3, 2, 6, 4};
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;
  Sort(arr);
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;

  int arr2[]{2, 1, 5, 8, 3};
  for (auto x : arr2) {
    cout << x << " ";
  }
  cout << endl;

  Sort2(arr2, Comp1);
  for (auto x : arr2) {
    cout << x << " ";
  }
  cout << endl;

  Sort2(arr2, Comp2);
  for (auto x : arr2) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
