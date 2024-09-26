#include <stdio.h>
#include <stdlib.h>

int main() {
  /* malloc */
  /* In C++, as no implicit typecast like C, (void*) not converted to (int*)
   */
  // int *p = malloc(sizeof(int)); // error

  int *p = (int *)malloc(sizeof(int));

  *p = 5;
  printf("*p is %d\n", *p);
  printf("p pointing to address %p\n", (void *)p);
  printf("After Freeing===>\n");
  free(p);
  /* after freeing the pointer, the memory is invalidated,
     but p is pointing to the address.
     p is a Dangling pointer, pointing to an invalid address.
  */
  printf("p pointing to address %p\n", (void *)p);

  /* Dangling pointer is very dangerous, because: accidentally if
     we free or access p, will crash the program */
  // free(p); // Program crashes double free detected

  /* Best practice is always make the pointer NULL after freeing */
  p = NULL;
  printf("After Nullyfying===>\n");
  printf("p pointing to address %p\n", (void *)p);
  free(p); // Program wont crash, we can free NULL ptr.

  /* Calloc */
  int *p2 = (int *)calloc(
      1,
      sizeof(int)); // Arguments are number of elements and size of each element
  // Difference with malloc is with calloc, the memory get initialized to zero

  /* whenever you allocate always check for valid memory address is returned or
   * not */
  if (p2 == NULL) {
    printf("Invalid memory address, no allocation");
    return -1;
  }
  printf("Value of *p2 initialized by calloc is %d\n",
         *p2); // Calloc initializes to zero

  // Allocating array

  /* Calloc */
  int *p3 = (int *)calloc(5, sizeof(int)); // 5 is the number of elements

  /* Malloc */
  int *p4 = (int *)malloc(5 * sizeof(int));
  /* as p2, p3, p4 are not freed, they lead to memory leaks */
  return 0;
}
