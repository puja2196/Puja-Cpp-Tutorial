#include <iostream>

using namespace std;

class Car {
  float fuel{0.0f};
  static int totalCount; // Static data member, specific to class, not bound to
                         // each object

public:
  Car() { totalCount++; }
  static void Show() {
    /* Static member function can't access non-static data member, only it is
       used to access the static data member. */
    // cout << fuel; // Error
    cout << "Total number of objects: " << totalCount << endl;
  }
};

/* Static data member initialization */
int Car::totalCount = 0;

int main() {
  Car::Show();
  Car c1;
  Car c2, c3;
  Car::Show();
  return 0;
}
