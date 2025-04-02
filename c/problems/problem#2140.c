#include <stdlib.h>

long long mostPoints(int **questions, int n, int *questionsColSize) {
  long long *dp = calloc(n, sizeof(long long));

  for (int i = 0; i < n; i++) {
    if (i - 1 >= 0 && dp[i] < dp[i - 1]) {
      dp[i] = dp[i - 1];
    }
    long long k = dp[i] + (long long)questions[i][0];
    int j = i + questions[i][1] + 1;
    if (j < n && dp[j] < k) {
      dp[j] = k;
    }
  }

  long long ans = dp[0] + (long long)questions[0][0];
  for (int i = 1; i < n; i++) {
    if (dp[i] + (long long)questions[i][0] > ans) {
      ans = dp[i] + (long long)questions[i][0];
    }
  }

  *questionsColSize = 2;
  free(dp);
  return ans;
}
