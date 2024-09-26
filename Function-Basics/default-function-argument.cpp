#include <iostream>
using namespace std;

void printWindow(const char *title, int x = -1, int y = -1, int z = -1) {
  cout << "title is " << title << endl;
  cout << "x is " << x << endl;
  cout << "y is " << y << endl;
  cout << "z is " << z << endl;
}

int main() {
  printWindow("Puja", 12, 10, 3); // Puja 12 10 3
  printWindow("Puja Saha", 3);    // Puja 3 -1 -1
  return 0;
}
