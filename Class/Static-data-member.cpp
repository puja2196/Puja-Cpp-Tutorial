#include <iostream>

using namespace std;

class Car {
  float fuel;
  static int totalCount; // Static data member, specific to class, not bound to
                         // each object

public:
  Car() {
    fuel = 0.0f;
    totalCount++;
  }

  Car(float amount) {
    fuel = amount;
    totalCount++;
  }

  void show() { cout << "Total number of objects are: " << totalCount << endl; }
};

/* Static data member initialization */
int Car::totalCount = 0;

int main() {
  /* Static data member initialization */
  Car c1;

  c1.show();
  Car c2(4.5f);
  Car c3;
  c3.show();
  return 0;
}
