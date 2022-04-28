#include "test/test.h"

int solve(int* prices, int n) {
  int ans, buy, curr, i, p;

  ans = 0;
  buy = curr = prices[0];

  for (i = 1; i < n; i++) {
    p = prices[i];
    if (p >= curr)
      curr = p;
    else {
      ans += curr - buy;
      buy = curr = p;
    }
  }

  ans += curr - buy;
  return ans;
}

int run_test(void) {
  int* arr;
  int n;

  arr = read_arr(&n);
  if (arr == NULL)
    return 0;

  n = solve(arr, n);
  printf("%d\n", n);
  free(arr);

  return 1;
}
