#include <iostream>

using namespace std;

/* Function returning by value returns r-value */
int Add(int &x, int &y) { return (x + y); }

/* Function returing the reference returns l-value */
/* We can assign some value to the return of function
   So the function can be in the left hand side */
int &Transform(int &x) {
  x *= x;
  return x;
}

int main() {

  /* x, y and z are l-values, because they have a name and can be assigned to
     values 1, 2 and 3 are r-values, because those are temporaries and can't be
     assigned to any other value, they can't come in the left hand side of the
     assignment */
  int x = 1;
  int y = 2;
  int z = 3;

  /* Expression returns r-value */
  int result = x * y + z;

  /* Expression returns l-value */
  ++x = 6;
}
