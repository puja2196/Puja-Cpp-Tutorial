#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p = malloc(sizeof(int));
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
  free(p); // Program wont crash, we can free NULL ptr.
  return 0;
}
