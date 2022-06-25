#include "test/test.h"

#define I32MAX ((int)0x7fffffff)
#define I32MIN ((int)0x80000000)

#define I32MAX_Y (I32MAX % 10)
#define I32MIN_Y (I32MIN % 10)

int solve(int x) {
  int result = 0;
  while (x) {
    int y = x % 10;
    if ((result > I32MAX / 10) || (result < I32MIN / 10))
      return 0;
    if ((result == I32MAX / 10) && (y > I32MAX_Y))
      return 0;
    if ((result == I32MIN / 10) && (y < I32MIN_Y))
      return 0;
    result = result * 10 + y;
    x = x / 10;
  }
  return result;
}

int run_test(void) {
  int x;
  if (read_int(&x) == 0)
    return 0;

  printf("%d\n", solve(x));
  return 1;
}
