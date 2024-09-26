#include "Constant-Member-function.h"
#include <iostream>

using namespace std;

int main() {
  const Car c1;
  /* If you instantiate an object with "const", you can't call non-constant
   * functions */
  /*
  c1.FillFuel(6);
  c1.Accelerate();
  c1.Accelerate();
  c1.Accelerate();
  c1.Accelerate();
  */
  /* Make some function as constant which doesn't change the members of the
    class and call it via constant object */
  cout << "For object c1:=>\n";
  c1.Dashboard();

  return 0;
}
