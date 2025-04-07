#include <stdlib.h>

int comp(const void *elem1, const void *elem2) {
  int f = *((int *)elem1);
  int s = *((int *)elem2);
  if (f > s)
    return 1;
  if (f < s)
    return -1;
  return 0;
}

int *largestDivisibleSubset(int *nums, int n, int *returnSize) {
  qsort(nums, n, sizeof(int), comp);

  int *next = malloc(n * sizeof(int));
  int *len = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    len[i] = 1;
    next[i] = -1;
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = i + 1; j < n; j++) {
      if (nums[j] % nums[i] == 0 && len[i] < len[j] + 1) {
        len[i] = len[j] + 1;
        next[i] = j;
      }
    }
  }
  int max_len = 0;
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (len[i] > max_len) {
      max_len = len[i];
      x = i;
    }
  }
  int *ans = malloc(max_len * sizeof(int));
  *returnSize = max_len;
  int i = 0;

  while (x != -1) {
    ans[i] = nums[x];
    x = next[x];
    i++;
  }

  free(next);
  free(len);

  return ans;
}
