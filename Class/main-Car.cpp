#include "Car.h"
#include <iostream>

using namespace std;

int main() {
  Car c1; /* Default constructor gets invoked automatically when
             the object is created without initialization. */

  /* Default constructor is synthesized automatically if no other
     user defined constructor exists */
  c1.FillFuel(6);
  c1.Accelerate();
  c1.Accelerate();
  c1.Accelerate();
  c1.Accelerate();
  cout << "For object c1:=>\n";
  c1.Dashboard();

  Car c2(5);
  c2.Accelerate();
  c2.Accelerate();
  c2.Accelerate();
  c2.Accelerate();
  cout << "For object c2:=>\n";
  c2.Dashboard();

  return 0;
}
