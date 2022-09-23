#include "test/test.h"

#define MODULAR 1000000007

int solve(int n) {
  unsigned long long result = 0;
  int pow2logn = 1;
  int logn = 0;
  for (int i = 1; i <= n; i++) {
    if (i >= pow2logn) {
      pow2logn <<= 1;
      logn++;
    }
    result = ((result << logn) + i) % MODULAR; 
  }
  return result;
}

int run_test(void) {
  int n, c;

  c = read_int(&n);
  printf("%d\n", solve(n));

  return c;
}
