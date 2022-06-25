#include "test/test.h"

int cmp_int(const void* l, const void* r) {
  return *(int*)l - *(int*)r;
}

int* solve(int* nums1, int l1, int* nums2, int l2, int* rl) {
  int cap = 0;
  int* result = NULL;
  *rl = 0;

  qsort(nums1, l1, sizeof(int), cmp_int);
  qsort(nums2, l2, sizeof(int), cmp_int);

  int i, j;
  i = j = 0;

  while (i < l1 && j < l2) {
    int n1 = nums1[i];
    int n2 = nums2[j];
    if (n1 == n2) {
      if (*rl == cap) {
        cap = cap ? (cap << 1) : 1;
        result = realloc(result, cap * sizeof(int));
      }
      result[(*rl)++] = n1;
      i++;
      j++;
    }
    else if (n1 < n2)
      i++;
    else
      j++;
  }

  return result;
}

int* solve(int* nums1, int l1, int* nums2, int l2, int* rl) {
  int cap = 0;
  int* result = NULL;
  *rl = 0;

  qsort(nums1, l1, sizeof(int), cmp_int);
  qsort(nums2, l2, sizeof(int), cmp_int);

  int i, j;
  i = j = 0;

  while (i < l1 && j < l2) {
    int n1 = nums1[i];
    int n2 = nums2[j];
    if (n1 == n2) {
      if (*rl == cap) {
        cap = cap ? 1 : (cap << 1);
        result = realloc(result, cap * sizeof(int));
      }
      result[(*rl)++] = n1;
      i++;
      j++;
    }
    else if (n1 < n2)
      i++;
    else
      j++;
  }

  return result;
}

int run_test(void) {
  int* nums1;
  int l1;
  int* nums2;
  int l2;

  nums1 = read_arr(&l1);
  if (nums1 == NULL)
    return 0;

  nums2 = read_arr(&l2);
  if (nums2 == NULL)
    return 0;

  int result_length;
  int* result = solve(nums1, l1, nums2, l2, &result_length);

  print_arr(result, result_length);
  free(result);

  return 1;
}
