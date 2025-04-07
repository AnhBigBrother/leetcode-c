#include <stdlib.h>

int minimumSum(int *nums, int n) {
  int *i_min_arr = malloc(sizeof(int) * n);
  int *k_min_arr = malloc(sizeof(int) * n);
  i_min_arr[0] = -1;
  k_min_arr[n - 1] = -1;
  int i_min = 1e8 + 1;
  int k_min = 1e8 + 1;

  for (int i = 1; i < n; i++) {
    if (i_min > nums[i - 1]) {
      i_min = nums[i - 1];
    }
    if (nums[i] > i_min) {
      i_min_arr[i] = i_min;
    } else {
      i_min_arr[i] = -1;
    }
  }
  for (int i = n - 2; i >= 0; i--) {
    if (k_min > nums[i + 1]) {
      k_min = nums[i + 1];
    }
    if (nums[i] > k_min) {
      k_min_arr[i] = k_min;
    } else {
      k_min_arr[i] = -1;
    }
  }

  int ans = -1;
  for (int i = 1; i < n - 1; i++) {
    if (i_min_arr[i] > 0 && k_min_arr[i] > 0 &&
        (ans == -1 || ans > i_min_arr[i] + nums[i] + k_min_arr[i])) {
      ans = i_min_arr[i] + nums[i] + k_min_arr[i];
    }
  }

  free(i_min_arr);
  free(k_min_arr);

  return ans;
}
