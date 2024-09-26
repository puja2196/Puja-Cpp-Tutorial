#include <memory>

using namespace std;

int main() {
  // Fixed Dynamic Array using Smart Pointers
  /*
     unique_ptr<int> p{new int[]{1,2,3,4}};
     p[0] = 12;
     The above won't work, so add [] in the type of unique_ptr.
  */
  unique_ptr<int[]> p{new int[]{1, 2, 3, 4}};
  p[0] = 12;

  shared_ptr<int[]> sp{new int[]{1, 2, 3, 4}};
  p[0] = 12;
}
