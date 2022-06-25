#include "test/test.h"

int solve(int* nums, int n) {
  int mod = 0;
  for (int i = 1; i < n; i++) {
    if (nums[i-1] <= nums[i])
      continue;
    if (mod++)
      return 0;
    if (i == 1 || nums[i] >= nums[i-2])
      nums[i-1] = nums[i];
    else
      nums[i] = nums[i-1];
  }

  return 1;
}

int run_test(void) {
  int* arr;
  int n;

  arr = read_arr(&n);
  if (arr == NULL)
    return 0;

  if (solve(arr, n))
    printf("true\n");
  else
    printf("false\n");
  free(arr);

  return 1;
}
