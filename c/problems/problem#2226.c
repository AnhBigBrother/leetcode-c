int maximumCandies(int *candies, int candiesSize, long long k) {
  int max_pile = candies[0];
  for (int i = 1; i < candiesSize; i++) {
    max_pile = candies[i] > max_pile ? candies[i] : max_pile;
  }
  int l = 1, r = max_pile;
  while (l < r) {
    int m = (l + r + 1) / 2;
    long long sum = 0;
    for (int i = candiesSize - 1; i >= 0; i--) {
      sum += (long long)(candies[i] / m);
    }
    if (sum >= k) {
      l = m;
    } else {
      r = m - 1;
    }
  }

  long long sum = 0;
  for (int i = candiesSize - 1; i >= 0; i--) {
    sum += (long long)(candies[i] / r);
  }
  if (sum < k) {
    return 0;
  }

  return r;
}
