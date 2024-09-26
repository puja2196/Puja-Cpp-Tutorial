#include <iostream>

using namespace std;

/* Wrong program

int main()
{
    int sum = add(1, 2); // We dont know the type of "add"
                         // so we need to declare the function "add" before
using it. cout << sum; return 0;
}

int add(int x, int y)
{
    return (x+y);
}

*/

/* Correct program-1

int add(int,int); // Added function declaration before using it.

int main()
{
    int sum = add(1, 2);

    cout << sum;
    return 0;
}

int add(int x, int y)
{
    return (x+y);
}
*/

/* Correct Program 2 */
/* If we define the function before use, that is also correct. But this is not
 * done for normal functions. For inline function and function template, we
 * define the function before use.
 */

int add(int x, int y) { return (x + y); }

int main() {
  int sum = add(1, 2); // function definition was there before, so compiles fine

  cout << sum;
  return 0;
}
