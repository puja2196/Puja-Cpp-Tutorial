#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Initialization
  vector<int> v{1, 2, 3};

  // Grow vector dynamically inserting elements at the back of the vector
  for (int i = 0; i < 3; i++) {
    v.push_back(i * 2);
  }

  // Size of the vector
  auto sz = v.size();

  // Accessing array element
  // Modifying the array element
  v[2] = 200;
  cout << "Reading vector elements using for loop: ";
  for (auto i = 0; i < sz; i++) {
    cout << v[i] << " ";
  }

  cout << "\nReading vector elements using range based for loop: ";
  for (auto x : v) {
    cout << x << " ";
  }

  cout << "\nReading vector elements using iterators: ";
  auto itr = v.begin();
  while (itr != v.end()) {
    cout << (*itr) << " ";
    itr++;
  }
  cout << endl;

  // Removing element from a position
  auto itr2 = v.begin() + 1; // Delete 1st element
  v.erase(itr2);
  cout << "After deleting the 1st element, the vector is: ";
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;

  // Inserting element in a position
  itr2 = v.begin() + 2; // Insert 500 in the 2nd position
  v.insert(itr2, 500);

  cout << "After Inserting 500 in the 2nd position, the vector is: ";
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
