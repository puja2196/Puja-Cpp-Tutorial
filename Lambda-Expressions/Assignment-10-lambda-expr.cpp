/*Create lambda expressions & their equivalent function objects for the
following functions.

T Max(T, T); //Return largest element
bool Greater(T, T) ; //Return true if first argument is greater than the second
bool Less(T, T) ; //Return true if first argument is less than the second
pair<T,T> MinMax(ItrBegin, ItrEnd) ;//Accept iterators of any container and
return the largest and smallest element from that container.
*/

#include <iostream>

using namespace std;

template <typename T, typename Comparator> T Max(T x, T y, Comparator comp) {
  return comp(x, y);
}

template <typename T, typename Comparator>
bool Compare(T x, T y, Comparator comp) {
  return comp(x, y);
}

int main() {

  int x{2}, y{3};
  cout << Max(x, y, [](auto x, auto y) { return (x > y) ? x : y; }) << endl;
  auto greater = [](auto x, auto y) { return (x > y) ? true : false; };
  auto less = [](auto x, auto y) { return (x < y) ? true : false; };

  cout << "isGreater = : " << Compare(3, 5, greater);
  cout << "\nisLess = : " << Compare(2, 5, less);
  return 0;
}
