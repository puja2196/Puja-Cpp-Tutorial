#include <iostream>

using namespace std;

int main() {
  int a = 5, b = 2;
  float f = a;     /* Even though the types are different, compiler will perform
                      implicit tyoe casting from int to float,
                      But the casting may be wrong sometimes */
  float g = a / b; /* Expected value is: 5/2 = 2.5 but actual is 2. there is
                     dataloss because Integer divided integer gives an integer
                     which is 2, then its type casted to float 2.0f */
  cout << "g = " << g << endl;

  /* Solution is apply float cast to "a". The below is C-Style casting */
  float h = (float)a / b;
  cout << "h = " << h << endl;

  /* CPP style casting */
  float p = static_cast<float>(a) / b;
  cout << "p = " << p << endl;

  /* Why static_cast is important over C-style cast? */
  // char *c = &a; // error, can't convert int* to char*
  //  Apply C-style cast: No error: dangerous
  int d = 256;
  /*
      char *c = (char*)&d; // char is of 1 byte and int is of 4 bytes and c will
  point to LSB 1 byte of d. *c = 1; // Updating "c" will affect "d" incorrectly.
      cout << "d = " << d << endl;
  To avoid this use "static_cast" so that compiler will check validity before
  typecasting.
  */
  // char *c = static_cast<char*>(&d); // Report error as incompatible types

  /* If your intent is to get the address of d, rather than doing any
     modification, you can do typecast between incompatible types using
     reinterpret_cast */
  char *c = reinterpret_cast<char *>(&d);

  /* Difference between reinterpret_cast and C-Style casting is: */
  const int e = 123;
  int *p2 = (int *)&e; // &e will be type-casted to (int*), discarding the const
                       // qualifier and then assigned.
                       /* C-Style casting will discard the const qualifier
                          reinterpret_cast will not discard the qualifier of the source. i.e. const,
                          static will be populated to the assigned type as well. So we get error for
                          the following:
                          */
  // int *p3 = reinterpret_cast<int*>(&e); // Error: can't assign int* to const
  // int*.
  int *p4 = const_cast<int *>(&e);
  return 0;
}
