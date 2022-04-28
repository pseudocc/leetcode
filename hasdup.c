#include "test/test.h"

int cmp_int(const void* l, const void* r) {
  return *(int*)l - *(int*)r;
}

int solve(int* nums, int n) {
  int last, i;

  qsort(nums, n, sizeof(int), cmp_int);
  last = nums[0];

  for (i = 1; i < n; i++) {
    if (nums[i] == last)
      return 1;
    last = nums[i];
  }

  return 0;
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
