#include "test/test.h"

int solve(int* nums, int n) {
  int xor, i;
  for (i = 0, xor = 0; i < n; i++)
    xor ^= nums[i];
  return xor;
} 

int run_test(void) {
  int* arr;
  int n;

  arr = read_arr(&n);
  if (arr == NULL)
    return 0;

  n = solve(arr, n);
  printf("%d\n", n);

  return 1;
}
