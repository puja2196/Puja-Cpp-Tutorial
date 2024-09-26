#include <cstring>
#include <iostream>

using namespace std;

template <typename T, size_t arrSize>
T ArraySum(const T (&pArr)[arrSize]) { // Returns the sum of array elements
  T sum{};
  for (auto i = 0; i < arrSize; i++) {
    sum += pArr[i];
  }
  return sum;
}

template <typename T, size_t arrSize>
T Max(const T (&pArr)[arrSize]) { // Return the largest element in the array
  T max1{pArr[0]};
  for (auto i = 1; i < arrSize; i++) {
    if (pArr[i] > max1) {
      max1 = pArr[i];
    }
  }
  return max1;
}

/* Specialize Max function for array of strings => const char * */
/* The problem is with this we can't assign pArr[0](const char *) to (char
*)max1.

template<size_t arrSize>
const char* Max(const char* (&pArr)[arrSize]) { //Return the largest element in
the array char* max1{pArr[0]}; for (auto i=1; i<arrSize; i++) { if
(strcmp(pArr[i],max1) > 0) { max1 = pArr[i];
        }
    }
    return max1;
}
*/

template <size_t arrSize>
string Max(string (&pArr)[arrSize]) { // Return the largest element in the array
  string max1{pArr[0]};
  for (auto i = 1; i < arrSize; i++) {
    if (pArr[i] > max1) {
      max1 = pArr[i];
    }
  }
  return max1;
}

template <typename T, size_t arrSize>
std::pair<T, T> MinMax(const T (
    &pArr)[arrSize]) { // Return the smallest and largest element in a pair
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

  int arr[4]{3, 10, 1, 9};
  auto z = ArraySum(arr);
  cout << "ArraySum = " << z << endl;

  z = Max(arr);
  cout << "Max = " << z << endl;

  pair<int, int> p = MinMax(arr);
  cout << "p = (" << p.first << ", " << p.second << " )\n";

  float arr1[5]{3.4f, 0.3f, 10.1f, 1.2f, 9.7f};
  auto z1 = ArraySum(arr1);
  cout << "ArraySum = " << z1 << endl;

  z1 = Max(arr1);
  cout << "Max = " << z1 << endl;

  pair<float, float> p1 = MinMax(arr1);
  cout << "p1 = (" << p1.first << ", " << p1.second << " )\n";

  // const char* arr2[4]{"A","B","C","D"};
  string arr2[4]{"A", "B", "C", "D"};
  auto s1 = Max(arr2);

  cout << "Max is = " << s1 << "\n";
  return 0;
}
