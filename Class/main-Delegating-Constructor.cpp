#include "Delegating-Constructor.h"
#include <iostream>

using namespace std;

int main() {
  Car c1;
  cout << "For object c1:=>\n";
  c1.Dashboard();

  Car c2(5);
  cout << "For object c2:=>\n";
  c2.Dashboard();

  Car c3(4.0f, 7);
  cout << "For object c3:=>\n";
  c3.Dashboard();

  return 0;
}
