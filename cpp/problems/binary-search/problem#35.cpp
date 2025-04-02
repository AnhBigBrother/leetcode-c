#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target) {
  int n = nums.size();
  int l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (nums[m] < target) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  if (nums[r] < target) {
    return r + 1;
  }
  return r;
}
