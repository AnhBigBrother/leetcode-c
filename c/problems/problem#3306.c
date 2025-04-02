#include <stdlib.h>

int helper3306(int *aa, int *ee, int *ii, int *oo, int *uu, int *kk, int k,
               int left, int right) {
  int l = left, r = right - 5;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (*(aa + right) - *(aa + m) > 0 && *(ee + right) - *(ee + m) > 0 &&
        *(ii + right) - *(ii + m) > 0 && *(oo + right) - *(oo + m) > 0 &&
        *(uu + right) - *(uu + m) > 0 && *(kk + right) - *(kk + m) == k) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  if (!(*(aa + right) - *(aa + l) > 0 && *(ee + right) - *(ee + l) > 0 &&
        *(ii + right) - *(ii + l) > 0 && *(oo + right) - *(oo + l) > 0 &&
        *(uu + right) - *(uu + l) > 0)) {
    return 0;
  }
  return l - left + 1;
}

long long countOfSubstrings(char *word, int k) {
  int n = 0;
  for (int i = 0; word[i]; i++) {
    n++;
  }
  int *aa = malloc((n + 1) * sizeof(int));
  int *ee = malloc((n + 1) * sizeof(int));
  int *ii = malloc((n + 1) * sizeof(int));
  int *oo = malloc((n + 1) * sizeof(int));
  int *uu = malloc((n + 1) * sizeof(int));
  int *kk = malloc((n + 1) * sizeof(int));

  *(aa) = 0;
  *(ee) = 0;
  *(ii) = 0;
  *(oo) = 0;
  *(uu) = 0;
  *(kk) = 0;

  for (int i = 1; i <= n; i++) {
    *(aa + i) = *(aa + i - 1);
    *(ee + i) = *(ee + i - 1);
    *(ii + i) = *(ii + i - 1);
    *(oo + i) = *(oo + i - 1);
    *(uu + i) = *(uu + i - 1);
    *(kk + i) = *(kk + i - 1);

    switch (word[i - 1]) {
    case 'a':
      *(aa + i) = *(aa + i) + 1;
      break;
    case 'e':
      *(ee + i) = *(ee + i) + 1;
      break;
    case 'i':
      *(ii + i) = *(ii + i) + 1;
      break;
    case 'o':
      *(oo + i) = *(oo + i) + 1;
      break;
    case 'u':
      *(uu + i) = *(uu + i) + 1;
      break;

    default:
      *(kk + i) = *(kk + i) + 1;
      break;
    }
  }

  long long ans = 0;
  int kkk = 0;
  int l = 0;

  for (int i = 1; i <= n; i++) {
    if (!(word[i - 1] == 'a' || word[i - 1] == 'e' || word[i - 1] == 'i' ||
          word[i - 1] == 'o' || word[i - 1] == 'u')) {
      kkk++;
    }
    while (kkk > k) {
      if (!(word[l] == 'a' || word[l] == 'e' || word[l] == 'i' ||
            word[l] == 'o' || word[l] == 'u')) {
        kkk--;
      }
      l++;
    }
    if (kkk == k) {
      ans += (long long)(helper3306(aa, ee, ii, oo, uu, kk, k, l, i));
    }
  }

  free(aa);
  free(ee);
  free(ii);
  free(oo);
  free(uu);
  free(kk);

  return ans;
}
