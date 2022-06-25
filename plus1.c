#include "test/test.h"

int* solve(int* digits, int n, int* rn) {
  int* result = malloc(sizeof(int) * n);
  memcpy(result, digits, sizeof(int) * n);
  *rn = n;

  int i = n - 1;
  int carry = 1;
  while (i >= 0 && carry) {
    int t = result[i] + carry;
    carry = t / 10;
    result[i--] = t % 10;
  }

  if (carry) {
    result = realloc(result, sizeof(int) * (n + 1));
    memmove(&result[1], result, sizeof(int) * n);
    *result = carry;
    *rn = n + 1;
  }

  return result;
}

int run_test(void) {
  int* digits;
  int n;

  digits = read_arr(&n);
  if (digits == NULL)
    return 0;

  int* plus1 = solve(digits, n, &n);
  print_arr(plus1, n);
  free(plus1);

  return 1;
}
