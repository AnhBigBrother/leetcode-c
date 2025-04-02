#include <stdlib.h>

int numberOfAlternatingGroups(int *colors, int n, int k) {
  colors = realloc(colors, (n + k) * sizeof(int));
  for (int i = 0; i < k; i++) {
    colors[n + i] = colors[i];
  }
  int count = 0;
  int l = 0, r = 1;
  while (r < n + k) {
    if (r - l == k) {
      count++;
      l++;
    }
    if (colors[r] == colors[r - 1]) {
      l = r;
    }
    r++;
  }
  free(colors);
  return count;
}