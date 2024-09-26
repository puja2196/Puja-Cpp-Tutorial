#include <memory>
using namespace std;

class Point {
public:
  int x, y;
  Point(int x, int y) {}
};

int main() {
  // unique_ptr<int> p{new int{5}};

  auto p = make_unique<int>(5);
  auto ptr = make_unique<Point>(1, 2);
  auto pArr = make_unique<int[]>(5); // Array with 5 integers
  pArr[0] = 100;                     // Initialize

  // make_shared is added in C++20
  auto p1 = make_shared<int>(5);
  auto ptr1 = make_shared<Point>(1, 2);
  auto pArr1 = make_shared<int[]>(5); // Array with 5 integers
  pArr1[0] = 100;                     // Initialize
}
