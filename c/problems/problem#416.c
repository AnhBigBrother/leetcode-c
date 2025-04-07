#include <stdbool.h>
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

bool canPartition(int *nums, int n) {
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += nums[i];
  }
  if (s % 2 == 1) {
    return false;
  }
  s /= 2;
  qsort(nums, n, sizeof(int), comp);
  bool *valid = calloc((s + 1), sizeof(bool));
  valid[0] = true;
  for (int i = 0; i < n; i++) {
    int x = nums[i];
    if (x > s) {
      break;
    }
    for (int val = s; val >= x; val--) {
      if (valid[val - x]) {
        valid[val] = true;
      }
    }
  }
  bool ans = valid[s];
  free(valid);
  return ans;
}
