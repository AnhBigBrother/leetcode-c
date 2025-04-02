#include <stdbool.h>

bool check(int *nums, int numsSize, int **queries, int queriesSize) {
  int *diff = (int *)malloc((numsSize + 1) * sizeof(int));
  for (int i = 0; i <= numsSize; i++) {
    diff[i] = 0;
  }
  for (int i = 0; i < queriesSize; i++) {
    int l = queries[i][0], r = queries[i][1], val = queries[i][2];
    diff[l] -= val;
    diff[r + 1] += val;
  }
  int w = 0;
  for (int i = 0; i < numsSize; i++) {
    w += *(diff + i);
    if (*(nums + i) + w > 0) {
      return false;
    }
  }
  free(diff);
  return true;
}

bool checkAllZero(int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > 0) {
      return false;
    }
  }
  return true;
}

int minZeroArray(int *nums, int numsSize, int **queries, int queriesSize,
                 int *queriesColSize) {
  if (checkAllZero(nums, numsSize)) {
    return 0;
  }
  int l = 0, r = queriesSize - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (check(nums, numsSize, queries, m + 1)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  if (!check(nums, numsSize, queries, l + 1)) {
    return -1;
  }
  return l + 1;
}