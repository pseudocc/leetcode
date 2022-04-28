#include <errno.h>
#include <string.h>
#include "test/test.h"

int* str2arr(const char* str, int len, int* n) {
  int i, j, k;
  char c, s;
  int* arr;
  char ibuf[12];

  i = j = k = s = *n = 0;
  memset(ibuf, 0, sizeof(ibuf));
  arr = NULL;

  for (; i < len; i++) {
    c = str[i];

    switch (s) {
    case 0:
      if (c == ' ')
        break;
      if (c == '[') {
        s = 1;
        break;
      }
      goto ABORT;
    case 1:
      if (c == ' ')
        break;
      s = 2;
      if (c == '-') {
        ibuf[j++] = c;
        break;
      }
    case 2:
      if (!j || *ibuf == '-')
        if (c == ' ')
          break;
      if (c >= '0' && c <= '9') {
        ibuf[j++] = c;
        break;
      }
      if (c == ',' || c == ']') {
        if (j && ibuf[j-1] != '-') {
          if (k == *n) {
            k = k ? k << 1 : 1;
            arr = realloc(arr, k * sizeof(int));
            if (arr == NULL) {
              fprintf(stderr, "realloc: %s\n", strerror(errno));
              exit(EXIT_FAILURE);
            }
          }
          arr[(*n)++] = atoi(ibuf);

          memset(ibuf, 0, sizeof(ibuf));
          j = 0;
          s = 1;

          if (c == ']')
            s = 3;
          break;
        }
      }
      goto ABORT;
    case 3:
      if (c == ' ' || c == '\n' || c == '\0')
        break;
ABORT:
    default:
      char strcp[len+1];
      strncpy(strcp, str, len);
      strcp[len] = '\0';
      fprintf(stderr, "unexpected character '%c' "
        "in '%s' at position %d.\n", c, strcp, i);
      exit(EXIT_FAILURE);
      break;
    }
  }

  return arr;
}

int* read_arr(int* n) {
  int* arr;
  char* line;
  size_t cap;
  ssize_t len;

  line = NULL;
  cap = *n = 0;

  if ((len = getline(&line, &cap, stdin)) != EOF) {
    arr = str2arr(line, len-1, n);
    free(line);
    return arr;
  }
  return NULL;
}

void print_arr(int* arr, int n) {
  int i;
  
  if (n < 0) {
    arr = arr + n;
    n = -n;
  }

  printf("[");
  for (i = 0; i < n - 1; i++)
    printf("%d,", arr[i]);
  if (n)
    printf("%d", arr[i]);
  printf("]\n");
}

int main(void) {
  while (run_test());
  return 0;
}
