#include "test/test.h"

int solve(int* nums, int n, int k) {
  int max;
  int pts = 0;

  for (int i = 0; i < k; i++)
    pts += nums[i];
  max = pts;

  for (int i = 1; i <= k; i++) {
    pts = pts - nums[k-i] + nums[n-i];
    max = max < pts ? pts : max;
  }

  return max;
}

int run_test(void) {
  int* nums;
  int n, k;

  nums = read_arr(&n);
  if (nums == NULL)
    return 0;
  if (read_int(&k) == 0 || k < 1 || k > n)
    return 0;

  printf("%d\n", solve(nums, n, k));
  free(nums);
  return 1;
}
