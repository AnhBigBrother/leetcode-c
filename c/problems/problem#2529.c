
int maximumCount(int *nums, int n) {
  int ans = 0;
  int l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (*(nums + m) < 0) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  ans = *(nums + l) < 0 ? l + 1 : 0;
  l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (*(nums + m) > 0) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  ans = *(nums + r) > 0 && (n - r) > ans ? n - r : ans;

  return ans;
}