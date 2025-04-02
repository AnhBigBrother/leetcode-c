#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int minCapability(int *nums, int n, int k) {
  int *vals = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    *(vals + i) = *(nums + i);
  }
  qsort(vals, n, sizeof(int), compare);
  int l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    bool flag = false;
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (flag) {
        flag = false;
        continue;
      }
      if (*(nums + i) <= *(vals + m)) {
        flag = true;
        count++;
      }
    }
    if (count >= k) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  int ans = vals[l];
  free(vals);
  return ans;
}
