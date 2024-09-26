#include <iostream>

using namespace std;

class Car {
  int passengers{0};

public:
  /* 1st Usage of this pointer */
  void AddPassengers(int passengers) {
    /* Treating both the passengers as argument/ local variables" */
    passengers = passengers;
  }
  void AddPassengers2(int passengers) {
    /* To distinguish between both the passengers use "this" */
    this->passengers = passengers;
  }

  /* 2nd Usage of this pointer */
  /* Suppose we have a member function with argument as object of the class.
     while calling the function from another function, we need to use "this". */
  void Foo(const Car &c) {}

  void Show() {
    Foo(*this);
    cout << "Number of passengers: " << passengers << endl;
  }
};
int main() {
  Car c1;
  c1.AddPassengers(3);
  c1.Show();
  c1.AddPassengers2(3);
  c1.Show();
  return 0;
}
