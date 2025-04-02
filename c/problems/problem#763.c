#include <stdlib.h>

int *partitionLabels(char *s, int *returnSize) {
  int lastIdx[26];
  for (int i = 0; s[i]; i++) {
    int c = s[i] - 97;
    lastIdx[c] = i;
  }
  int sz = 0;
  int last = 0;
  for (int i = 0; s[i]; i++) {
    int c = s[i] - 97;
    if (lastIdx[c] > last) {
      last = lastIdx[c];
    }
    if (last == i) {
      sz++;
    }
  }
  int *ans = malloc(sz * sizeof(int));
  int j = 0;
  last = 0;
  int count = 0;
  for (int i = 0; s[i]; i++) {
    count++;
    int c = s[i] - 97;
    if (lastIdx[c] > last) {
      last = lastIdx[c];
    }
    if (last == i) {
      ans[j] = count;
      j++;
      count = 0;
    }
  }
  *returnSize = sz;
  return ans;
}
