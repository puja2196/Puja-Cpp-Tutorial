#include "Integer.h"
#include <iostream>
using namespace std;

int main() {
  /* Initialization */
  Integer i1{5};
  /* Output:
  Integer(int)
  ~Integer()
  */

  /* Assignment */
  i1 = 6;
  /* i1 = Integer(6) => call Integer(int), then it is matching with the
     function "operator=(Integer&&)" as 6 is a r-value, so call the
     Move-Assignment Operator */

  return 0;
}
