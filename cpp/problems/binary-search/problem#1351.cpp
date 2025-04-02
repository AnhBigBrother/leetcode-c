#include <vector>

using namespace std;

int countNegatives(vector<vector<int>> &grid) {
  int m = grid.size(), n = grid[0].size();
  int rs = 0, re = m - 1;
  int ans = 0;
  while (rs < re) {
    int rm = (rs + re + 1) / 2;
    if (grid[rm][0] < 0) {
      re = rm - 1;
    } else {
      rs = rm;
    }
  }
  ans += (m - 1 - rs) * n;
  for (int i = 0; i <= rs; i++) {
    vector<int> row = grid[i];
    int l = 0, r = n - 1;
    while (l < r) {
      int x = (l + r) / 2;
      if (row[x] >= 0) {
        l = x + 1;
      } else {
        r = x;
      }
    }
    if (row[r] < 0 ) {
      ans += n-r;
    }
  }
  return ans;
}
