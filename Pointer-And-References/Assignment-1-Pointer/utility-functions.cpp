int Add(int *a, int *b) {
  // Add two numbers and return the sum
  return (*a + *b);
}

void AddVal(int *a, int *b, int *result) {
  // Add two numbers and return the sum through the third pointer argument
  *result = (*a + *b);
}

void Swap(int *a, int *b) {
  // Swap the value of two integers
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Factorial(int *a, int *result) {
  // Generate the factorial of a number and return that through the second
  // pointer argument
  if (*a == 0)
    return;
  *result = (*a) * (*result);
  *a = *a - 1;
  Factorial(a, result);
}
