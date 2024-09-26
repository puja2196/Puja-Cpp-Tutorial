#include <iostream>

using namespace std;

int main() {
  // Lambda Expression => Anonymous function object
  []() {
    cout << "Welcome to Lambda Expressions\n";
  }(); // Just have the invokation() after the definition, which will call the
       // lambda expression

  // Giving name to the lambda expression
  auto fn = []() { cout << "This is lambda expression named as fn\n"; };
  fn();

  cout << typeid(fn).name() << endl; // type of fn

  // Lambda Expression to add 2 integers and return their sum
  // -> <return_type> is not needed if the function is not returning anything or
  // returning same type only
  /* Case-1:
      auto sum = [](int x, int y)->double {
          return (x+y);
      };
  or Case-2:
  */
  auto sum = [](int x, int y) { return (x + y); };
  cout << "Sum = " << sum(3, 4) << endl; // Invoking the lambda expression

  // Generic Lambda using passing auto
  auto sum2 = [](auto x, auto y) { return (x + y); };
  cout << "Sum = " << sum2(3.1f, 4.3f) << endl;

  /* If you want Lambda expression to not throw any exception, use */
  auto sum3 = [](auto x, auto y) noexcept { return (x + y); };

  /* If you want Lambda expression to throw exception, use */
  auto sum4 = [](auto x, auto y) noexcept(false) { return (x + y); };

  return 0;
}
