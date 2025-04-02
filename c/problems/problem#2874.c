#include <stdlib.h>

long long maximumTripletValue(int *nums, int n) {
  int *max_before = malloc(n * sizeof(int));
  int *max_after = malloc(n * sizeof(int));
  max_before[0] = 0;
  max_after[n - 1] = 0;
  for (int i = 1; i < n; i++) {
    max_before[i] =
        nums[i - 1] > max_before[i - 1] ? nums[i - 1] : max_before[i - 1];
  }
  for (int i = n - 2; i >= 0; i--) {
    max_after[i] =
        nums[i + 1] > max_after[i + 1] ? nums[i + 1] : max_after[i + 1];
  }
  long long ans = 0;
  for (int i = 1; i < n - 1; i++) {
    int x = max_before[i], y = nums[i], z = max_after[i];
    long long val = (long long)(x - y) * (long long)z;
    if (ans < val) {
      ans = val;
    }
  }
  free(max_before);
  free(max_after);
  return ans;
}
