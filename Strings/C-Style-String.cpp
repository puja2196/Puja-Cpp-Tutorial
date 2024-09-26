#include <cstring>
#include <iostream>

using namespace std;

const char *CombineName(const char *first, const char *last) {

  char fullname[20];
  strcpy(fullname, first);
  strcat(fullname, last);
  /* we are returning the address of a temporary variable created in stack,
   It may point to some garbage value after returning */
  return fullname;
}

/* Instead of static array if we use dynamic array i.e. allocated in the heap,
can solve the problem */
const char *CombineNameDynamicMemoryAllocation(const char *first,
                                               const char *last) {

  char *fullname = new char[strlen(first) + strlen(last) + 1];
  strcpy(fullname, first);
  strcat(fullname, last);
  /* we are returning the address of a variable created in heap,
   the value will be preserved at the address after returning */
  return fullname;
}

int main() {

  char first[10];
  char last[10];

  cout << "Enter first name: ";
  cin.getline(first, 10);

  cout << "Enter last name: ";
  cin.getline(last, 10);

  // const char *fullname = CombineName(first, last);

  const char *fullname2 = CombineNameDynamicMemoryAllocation(first, last);

  // cout << "Full name is : " << fullname << endl;

  cout << "Full name by Dynamic Memory Allocationis : " << fullname2 << endl;
  /* As fullname2 pointing to an character array, delete the char array */
  delete[] fullname2;
  return 0;
}
