#include <vector>

using namespace std;

int search(vector<int> &nums, int target) {
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
  if (nums[l] != target) {
    return -1;
  }
  return l;
}
