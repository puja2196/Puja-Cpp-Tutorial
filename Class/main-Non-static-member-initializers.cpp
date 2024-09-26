#include "Non-static-member-initializers.h"
#include <iostream>

using namespace std;

int main() {
  Car c1; /* Default constructor gets invoked automatically when
             the object is created without initialization. */

  /* Default constructor is synthesized automatically if no other
     user defined constructor exists */

  /* When called with default constructor, the member "fuel" will get updated
     with 0 but other members "speed" and "passangers" will be getting from the
     initializers while decalration of the data members */
  cout << "For object c1:=>\n";
  c1.Dashboard();

  Car c2(5);
  /* When called with parameterized constructor, the member "fuel" will get
    updated with 5 but other members "speed" and "passangers" will be getting
    from the initializers while decalration of the data members */
  cout << "For object c2:=>\n";
  c2.Dashboard();

  return 0;
}
