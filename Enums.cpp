#include <iostream>

using namespace std;

#define RED 0 // By Macros
const int GREEN = 1;

enum Color { BLUE, BLACK, GREY };

/* You can't assign one more enum in the same scope with same enum variable
Eg:
enum Light { WHITE, YELLOW, GREY };
// Error: You can't have GREY as already defined.
C++11 solves this problem using "Scoped Enums". Enumerators defined inside the
Scoped Enum are accessed using that scoped enum variable.
*/

enum class Fruit { MANGO, PINEAPPLE, GUAVA };

/* Juice is declared with char type */
/* You can assign value to any of the enumerator, the subsequent enumerator will
 * get value as that value + 1 and so on */
enum class Juice : char { MANGO, APPLE = 'c', ORANGE };

void FillColor(int color) {
  if (color == 0) {
  } else if (color == 1) {
  }
}

void FillColorWithEnum(Color c) {
  if (c == BLUE)
    cout << "fill blue\n";
  else if (c == BLACK)
    cout << "fill black\n";
  else if (c == GREY)
    cout << "fill grey\n";
}

void FillColorWithScopedEnum(Fruit c) {
  // Now to access MANGO, need to use Fruit::MANGO
  if (c == Fruit::MANGO)
    cout << "Mango\n";
  else if (c == Fruit::PINEAPPLE)
    cout << "Pinapple\n";
  else if (c == Fruit::GUAVA)
    cout << "Guava\n";
}

int main() {
  FillColor(0); // works
  FillColor(6); // Undefined Behavoiur
                /* We need to give a restricted range of values for Colors */
  Color c = BLACK;
  int x = GREY;
  /*
      Color c1 = 3; // Error: Can't assign int to Enum
  */
  Color c2 = BLACK;
  FillColorWithEnum(c2);

  FillColorWithEnum(GREY);

  // FillColorWithEnum(3);
  FillColorWithEnum(static_cast<Color>(2));
  /* using Scoped Enums */
  FillColorWithScopedEnum(Fruit::MANGO);          // Mango
  FillColorWithScopedEnum(static_cast<Fruit>(1)); // Pineapple

  // int y = Fruit::MANGO; // Compiler Error
  int y = static_cast<int>(Fruit::MANGO);
  // The Underlying type of enum is int, But you can define with any other
  // Integral type: char, long, etc. Eg: Juice declared with type "char"

  char d = static_cast<int>(Juice::ORANGE);
  return 0;
}
