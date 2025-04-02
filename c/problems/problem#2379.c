#include <stdio.h>
#include <string.h>

// Problem #2379
int minimumRecolors(char *blocks, int k) {
  int n = strlen(blocks);
  int cur = 0;
  for (int i = 0; i < k; i++) {
    if (blocks[i] == 'W') {
      cur++;
    }
  }
  int ans = cur;
  for (int i = k; i < n; i++) {
    if (blocks[i] == 'W') {
      cur++;
    }
    if (blocks[i - k] == 'W') {
      cur--;
    }
    ans = cur < ans ? cur : ans;
  }
  return ans;
}