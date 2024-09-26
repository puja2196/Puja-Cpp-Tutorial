#include <cassert>
#include <initializer_list>
#include <iostream>

using namespace std;

class Bag {
  int arr[10];
  int size{};

public:
  Bag(const initializer_list<int> values) {
    assert(values.size() <= 10);
    /* Access the elemets in initializer_list using iterators */
    auto it = values.begin();
    while (it != values.end()) {
      Add(*it); // Add in the arr
      it++;
    }
  }

  void Add(int val) {
    assert(size <= 10);
    arr[size++] = val;
  }

  int operator[](int index) { return arr[index]; }

  int Getsize() const { return size; }

  void Remove() { size--; }
};

void Print(initializer_list<int> val) {
  // We can access elements of initializer_list using iterators or range-based
  // for loop
  for (auto it : val) {
    cout << it << " ";
  }
}

int main() {

  /* initializer_list is used to store array of objects */
  initializer_list<int> data = {1, 2, 3, 4};

  /* Type of list is initializer_list */
  auto list = {
      1, 2, 3,
      4}; // Automatic type reference for {} elements is an initializer_list

  /* initializer_list is used to store object of container classes.
  container classes are those classes which store the object of other
  classes */

  Bag b{};
  b.Add(2);
  b.Add(3);
  b.Add(5);
  cout << "Bag b by adding elements using function: ";
  for (int i = 0; i < b.Getsize(); i++) {
    cout << b[i] << " ";
  }
  cout << endl;

  Bag b2 = {
      1, 4,
      5}; // The braced elements will be considered as initializer_list and so
          // we need a constructor in Bag with parameter as initializer_list

  cout << "Bag b2 by initializer list: ";
  for (int i = 0; i < b.Getsize(); i++) {
    cout << b[i] << " ";
  }
  cout << endl;

  cout << "Print the Initializer List:\n";

  Print({3, 2, 4, 5});
  return 0;
}
