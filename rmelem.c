#include "test/test.h"

int solve(int* nums, int n, int v) {
  int i, j;
  for (i = 0, j = 0; i < n; i++) {
    if (nums[i] == v)
      continue;
    nums[j++] = nums[i];
  }
  return j;
}

int run_test(void) {
  int* nums;
  int n, v, k;

  nums = read_arr(&n);
  if (nums == NULL)
    return 0;
  
	if (read_int(&v) == 0)
    return 0;

  k = solve(nums, n, v);
  print_arr(nums, k);

  free(nums);
  return 1;
}
