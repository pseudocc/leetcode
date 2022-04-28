#include "test/test.h"

void rotate_array(int* nums, int n) {
  int t, i;

  for (i = 0; i < n/2; i++) {
    t = nums[i];
    nums[i] = nums[n-i-1];
    nums[n-i-1] = t;
  }
}

void solve(int* nums, int n, int k) {
  k %= n;
  rotate_array(nums, n-k);
  rotate_array(nums+n-k, k);
  rotate_array(nums, n);
}

int run_test(void) {
  int* arr;
  int n, k, i;

  arr = read_arr(&n);
  if (arr == NULL)
    return 0;
  i = read_int(&k);
  if (!i)
    return 0;

  solve(arr, n, k);
  print_arr(arr, n);
  free(arr);

  return 1;
}
