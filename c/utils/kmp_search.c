#include "kmp_search.h"
#include <stdlib.h>
#include <string.h>

// find the longest prefix-subfix
int *find_lps(char *s, int s_len) {
  int *lps = calloc(s_len, sizeof(int));
  int l = 0;
  int i = 1;
  while (i < s_len) {
    if (s[i] == s[l]) {
      l++;
      lps[i] = l;
      i++;
    } else {
      if (l == 0) {
        lps[i] = 0;
        i++;
      } else {
        l = lps[l - 1];
      }
    }
  }
  return lps;
}

int kmp_search(char *base, int base_leng, char *sub, int sub_leng) {
  if (sub_leng > base_leng) {
    return -1;
  }
  int s_len = base_leng + sub_leng + 1;
  char *str = malloc(s_len * sizeof(char));
  strcpy(str, sub);
  strcat(str, " ");
  strcat(str, base);
  int *pi = find_lps(str, s_len);
  int ans = -1;
  for (int i = sub_leng + 1; i < s_len; i++) {
    if (pi[i] == sub_leng) {
      ans = i - 2 * sub_leng;
      break;
    }
  }
  free(str);
  free(pi);
  return ans;
}
