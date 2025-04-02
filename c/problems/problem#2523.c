#include <stdbool.h>
#include <stdlib.h>

int *closestPrimes(int left, int right, int *returnSize) {
  bool *sieve = malloc((right + 1) * sizeof(bool));
  for (int i = 0; i <= right; i++) {
    sieve[i] = false;
  }
  for (int k = 2; k * k <= right; k++) {
    if (!sieve[k]) {
      for (int i = k; k * i <= right; i++) {
        sieve[k * i] = true;
      }
    }
  }
  int p_size = 0;
  int p = left < 2 ? 2 : left;
  while (p <= right) {
    if (!sieve[p]) {
      p_size++;
    }
    p++;
  }

  int *primes = malloc(p_size * sizeof(int));
  p = left < 2 ? 2 : left;
  int i = 0;
  while (p <= right) {
    if (!sieve[p]) {
      primes[i] = p;
      i++;
    }
    p++;
  }
  *returnSize = 2;
  int *ans = malloc(2 * sizeof(int));
  ans[0] = -1, ans[1] = -1;
  i--;
  while (i > 0) {
    if (ans[1] - ans[0] == 0 || ans[1] - ans[0] >= primes[i] - primes[i - 1]) {
      ans[1] = primes[i];
      ans[0] = primes[i - 1];
    }
    i--;
  }
  free(sieve);
  free(primes);
  return ans;
}
