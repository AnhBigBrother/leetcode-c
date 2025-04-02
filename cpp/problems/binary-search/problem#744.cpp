#include <vector>

using namespace std;

char nextGreatestLetter(vector<char> &letters, char target) {
  int n = letters.size();
  int l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (letters[m] > target) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  if (letters[r] <= target) {
    return letters[0];
  }
  return letters[r];
}
