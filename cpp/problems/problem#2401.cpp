#include <vector>

using namespace std;

int longestNiceSubarray(vector<int> &nums) {
  int n = nums.size();
  if (n == 1) {
    return 1;
  }
  int l = 0, r = 1;
  int x = nums[0], ans = 1;

  while (r < n) {
    while (l < r && (x & nums[r]) != 0) {
      x ^= nums[l];
      l++;
    }
    x ^= nums[r];
    if (ans < r - l + 1) {
      ans = r - l + 1;
    }
    r++;
  }
  return ans;
}
