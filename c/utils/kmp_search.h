#pragma once

// Knuth–Morris–Pratt search algorithm.
// Search for occurrences of a string "sub" within a string "base",
// O(m+n) time and space complexity.
int kmp_search(char *base, int base_leng, char *sub, int sub_leng);
