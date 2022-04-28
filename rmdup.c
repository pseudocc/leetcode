#include "test/test.h"

int solve(int* nums, int n) {
  int i, j;
  i = j = 1;

  while (j < n) {
    if (nums[i-1] != nums[j])
      nums[i++] = nums[j];
    j++;
  }

  return i;
}

int run_test(void) {
  int* arr;
  int n;

  arr = read_arr(&n);
  if (arr == NULL)
    return 0;

  n = solve(arr, n);
  print_arr(arr, n);
  free(arr);

  return 1;
}
