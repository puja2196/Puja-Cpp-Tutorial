#include <iostream>
using namespace std;

/*
 Intent:
void DrawLine(int x1, int y1, int x2, int y2)
{
}
Not representative: so Point1 => (x1, y1), Point2 => (x2, y2)
*/

struct Point {
  int x;
  int y;
};

void DrawLine(Point p1, Point p2) {
  /* As data members of struct is public by default, we can
     access this using structVariable.datamember. */
  cout << "First point's x co-ordinate is: " << p1.x << endl;
}

int main() {
  Point p1{2, 3};
  Point p2{4, 5};
  DrawLine(p1, p2);
  return 0;
}
