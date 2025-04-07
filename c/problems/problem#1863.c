void backtrack(int *nums, int n, int i, int *x, int *ans) {
  *x ^= nums[i];
  *ans += *x;
  for (int j = i + 1; j < n; j++) {
    backtrack(nums, n, j, x, ans);
  }
  *x ^= nums[i];
}

int subsetXORSum(int *nums, int n) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = 0;
    backtrack(nums, n, i, &x, &ans);
  }
  return ans;
}
