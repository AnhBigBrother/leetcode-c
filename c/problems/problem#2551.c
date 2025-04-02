#include <stdlib.h>

int comp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

long long putMarbles(int *w, int n, int k) {
  if (n == 1 || n == k) {
    return 0;
  }
  int *gaps = malloc((n - 1) * sizeof(int));
  for (int i = 0; i < n - 1; i++) {
    gaps[i] = w[i] + w[i + 1];
  }
  qsort(gaps, n - 1, sizeof(int), comp);
  long long mi = 0, mx = 0;
  for (int i = 0; i < k - 1; i++) {
    mi += gaps[i];
    mx += gaps[n - 2 - i];
  }
  free(gaps);
  return mx - mi;
}
