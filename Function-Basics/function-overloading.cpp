#include <iostream>
using namespace std;

// Non-Overloaded Function
int Add(int x, int y) { return (x + y); }

// Overloaded function
int Add1(int x, int y) { return (x + y); }

double Add1(double x, double y) { return (x + y); }

/*
Print function even though return type is different, type and number of
arguments are same, So we cant overload.

int Print(int x)
{
    return x;
}
void Print(int x)
{

}
*/

void Print(int *x) {
  cout << "Called from the function with argument passed as pointer to a "
          "non-constant"
       << " *x = " << *x << endl;
}

void Print(int x) {
  cout << "Called from the function with argument passed as value "
       << " x = " << x << endl;
}

void Print(const int *x) {
  cout << "Called from the function with argument passed as pointer to a "
          "constant"
       << " *x = " << *x << endl;
}

/* When function overloading is occured, compiler creates mangled name for those
functions. To see the mangled name, use the commands:
>> g++ -c function-overloading.cpp -o function-overloading.o
>> nm function-overloading.o

Output: // We can see the mangled names:

000000000000019e T Add2
                 U _GLOBAL_OFFSET_TABLE_
00000000000001c6 T main
                 U __stack_chk_fail
0000000000000000 T _Z3Addii
0000000000000030 T _Z4Add1dd
0000000000000018 T _Z4Add1ii
0000000000000186 T _Z4Add2ii
00000000000000be T _Z5Printi
0000000000000058 T _Z5PrintPi
0000000000000120 T _Z5PrintPKi

Add2dd is unmangled as "Add2", because defined with extern "C". Others are
mangled names. extern "C" is indicating that the function can be used from "C"
or other languange.
*/
int Add2(int x, int y) { return (x + y); }

extern "C" double Add2(double x, double y) { return (x + y); }

/* For defining multiple extern "C" functions */
extern "C" {

int Add3(int x, int y) { return (x + y); }

void Print2(double x) {}
}

int main() {

  cout << "Using Function Add which is not overloaded for double arg types\n";
  int result1 = Add(2, 3);
  cout << "result1 =" << result1 << endl;

  /* If you want to add double with this function, prone to Dataloss, due to
   * arguments type-casing to int
   */
  int result2 = Add(2.4, 3.7);
  cout << "result2 = " << result2
       << endl; // 2.4 + 3.7 = 6.1 ==> typecasted after returining, so should
                // be 6. But it is 5. So Possible data loss.
                /*
                   So avoid that we can have a function "AddDouble" But the programmers may
                   get confused with so many names.               Hence, C++ provides function overloading
                   i.e. multiple functions with same name               In this case, the number/type of the
                   overloaded functions should be different.
                */
  cout << "Using Function Add which is overloaded for double arg types\n";
  int result3 = Add1(2, 3);
  cout << "result3 =" << result3 << endl; // 5

  double result4 = Add1(2.4, 3.7);
  cout << "result4 = " << result4 << endl; // 6.1

  int result5 =
      Add1(2.4, 3.7); // 6.1 is returned and type-casted to int , so 6.
  cout << "result5 = " << result5 << endl;

  int x = 7;
  Print(&x); // Call the 1st function matching the argument
  Print(x);  // Call the 2nd function matching the argument
             /* Const qualifier considered for overloading. */
             /* Other qualifiers we will see later */
  const int y = 9;
  Print(&y); // Call the 3rd function
  return 0;
}
