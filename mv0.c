#include "test/test.h"

int cmp_int0(const void* l, const void* r) {
  int vl, vr;
  vl = *(int*)l;
  vr = *(int*)r;
  if (vl == 0)
    return 1;
  if (vr == 0)
    return -1;
  return 0;
}

void solve(int* nums, int n) {
  qsort(nums, n, sizeof(int), cmp_int0);
}

int run_test(void) {
  int* arr;
  int n;

  arr = read_arr(&n);
  if (arr == NULL)
    return 0;

	solve(arr, n);
  print_arr(arr, n);
  free(arr);

  return 1;
}

