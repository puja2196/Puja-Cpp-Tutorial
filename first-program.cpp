/* Goal: To print something and learn all basic features */

/* Language Features */

/* 1. Comments */

// This is a single line comment

/*
This is a multiline
Comment
*/

/* 2. Include Header Files:
      iostream --> Header file for functions to perform I/O operation
                   and it doesn't end with ".h" beacuse it is a standard
                   header file.
*/
#include <iostream>

/* 3. Namespace declaration:
      cout object is inside the header file "iostream" but the object is not
      directly accesible because it is under the namespace "std". So we need to
      open the namespace using "using namespace" or you need to use "std::cout".
*/
using namespace std;

int main() {

  /* 4. Print Statement:
        << --> It is an insertion operator. cout represents the computer screen.
               So to insert into the screen we use "cout <<".
  */
  cout << "Hello C++!\n";

  /* 5. return to the operating system */

  return 0;
}
