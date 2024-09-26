#include <iostream>

using namespace std;

template <typename T> T Add(T x, T y) { // Return the sum of two elements
  return (x + y);
}

template <typename T>
T ArraySum(const T *pArr, size_t arrSize) { // Returns the sum of array elements
  T sum{pArr[0]};
  for (auto i = 1; i < arrSize; i++) {
    sum += pArr[i];
  }
  return sum;
}

template <typename T>
T Max(const T *pArr,
      size_t arrSize) { // Return the largest element in the array
  T max1{pArr[0]};
  for (auto i = 1; i < arrSize; i++) {
    if (pArr[i] > max1) {
      max1 = pArr[i];
    }
  }
  return max1;
}

template <typename T>
std::pair<T, T>
MinMax(const T *pArr,
       size_t arrSize) { // Return the smallest and largest element in a pair
  T max1{pArr[0]}, min1{pArr[0]};
  for (auto i = 1; i < arrSize; i++) {
    if (pArr[i] > max1) {
      max1 = pArr[i];
    }
    if (pArr[i] < min1) {
      min1 = pArr[i];
    }
  }
  return make_pair(min1, max1);
}

int main() {
  int x{3}, y{4};
  auto z = Add(x, y);
  cout << "Add(3,4) = " << z << endl;

  int arr[4]{3, 10, 1, 9};
  z = ArraySum(arr, 4);
  cout << "ArraySum = " << z << endl;

  z = Max(arr, 4);
  cout << "Max = " << z << endl;

  pair<int, int> p = MinMax(arr, 4);
  cout << "p = (" << p.first << ", " << p.second << " )\n";

  float x1{3.3f}, y1{1.4f};
  auto z1 = Add(x1, y1);
  cout << "Add = " << z1 << endl;

  float arr1[5]{3.4f, 0.3f, 10.1f, 1.2f, 9.7f};
  z1 = ArraySum(arr1, 5);
  cout << "ArraySum = " << z1 << endl;

  z1 = Max(arr1, 5);
  cout << "Max = " << z1 << endl;

  pair<float, float> p1 = MinMax(arr1, 5);
  cout << "p1 = (" << p1.first << ", " << p1.second << " )\n";

  return 0;
}
