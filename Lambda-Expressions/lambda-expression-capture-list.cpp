#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Writing the Sort function to use function-object
template <typename T, int size, typename Comparator>
void Sort(T (&arr)[size], Comparator comp) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = i + 1; j <= size - 1; j++) {
      if (comp(arr[i], arr[j])) {
        T temp = move(arr[i]);
        arr[i] = move(arr[j]);
        arr[j] = move(temp);
      }
    }
  }
}

// Writing ForEach Algrithm
template <typename T, int size, typename Operation>
void Foreach(T (&arr)[size], Operation op) {
  for (int i = 0; i < size; i++) {
    op(arr[i]);
  }
}

class Product {
  string name;
  float price;

public:
  Product(const string &n, float p) : name{n}, price{p} {}
  float Getprice() const { return price; }
  void Assignprice() {
    float taxes[]{12, 5, 5};
    float base{price};
    Foreach(taxes, [base, this](float x) {
      /* base is used in lambda, and is a local object defined before,
         need to be in capture list, also copy by value is fine bcz not
         changing, and just used, as price=> data member is used inside lambda,
         so need to have this in capture list */
      price += (x * base / 100);
    });
  }
};

int main() {

  int arr[]{1, 3, 2, 6, 4};
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;
  // writing the comparator using lambda expression
  Sort(arr, [](auto x, auto y) { return (x > y); });
  for (auto x : arr) {
    cout << x << " ";
  }
  cout << endl;

  // Using Foreach algorithm to have different operations through lambda
  // expression To print all array elements
  Foreach(arr, [](auto x) { cout << x << " "; });
  cout << endl;

  /* Important points about Lambda expression and Capture list:
     1. lambda expression can capture only local objects declared before it,
        can't access objects decalred after it.
     2. No need to capture global and static variables, as can be accessed by
     default within lambda expr
   */

  // Adding offset (defined outside the lambda) to each element of the array
  // using lambda expr
  int offset = 5;
  // Whenever you are using any variable defined outside the lambda, you need to
  // have this in Capture list [] Copy of offset will be created in the lambda
  // expression
  Foreach(arr, [offset](auto &x) { x += offset; });

  // Now Print again
  Foreach(arr, [](auto x) { cout << x << " "; });
  cout << endl;
  /* Now Suppose the offset is changing, for this you need to make the lambda
     expression mutable so that you can modify the items in capture list.
     Internally Lambda expr creates a data member for each item in the capture
     list and the operator function is const(), so can't modify any item in
     capture list */
  offset = 1;
  Foreach(arr, [offset](auto &x) mutable {
    x += offset;
    offset++;
  });

  // Now Print again
  Foreach(arr, [](auto x) { cout << x << " "; });
  cout << endl;

  /* Compute sum of all array elements */
  int sum{};
  /*
      Foreach(arr,[sum](auto &x) mutable {
                   sum+=x;
                  }
      );
  As sum is copied by value, the sum inside lambda gets modified, and not the
  original one, so we can pass by reference
  */
  Foreach(arr, [&sum](auto &x) { sum += x; });
  cout << "Sum = " << sum << endl;

  /* Suppose you want to pass both sum and offset as reference,
     If you want all the items in capture-list to be passed as reference, you
     can capture all using [&]. If all the items are passed by value, you can
     use [=]. If all items except sum is passed by value, use [=, &sum]. If all
     items except offset is passed by reference, use [&, offset].
  */
  sum = 0;
  offset = 0;
  Foreach(arr, [&](auto &x) {
    x += offset;
    sum += x;
    offset++;
  });

  Product p{"Chair", 700};
  p.Assignprice();
  cout << "New price = " << p.Getprice() << endl;

  /* We can have nested lambda expression */
  [](int x) {
    x *= 2;
    [](int x) { cout << x << "\n"; }(x);
  }(5);

  // Generalized lambda capture
  int x = 5;
  auto fn1 = [y = x](int arg) { return (y + arg); };
  cout << "fn1(3) = " << fn1(3) << endl;

  ofstream out;
  auto write = [out = move(out)](int x) mutable {
    // Making the state of out as non-changeable outside lambda using move and
    // as need to use only inside lambda
    out << x;
  };
  write(200);
  return 0;
}
