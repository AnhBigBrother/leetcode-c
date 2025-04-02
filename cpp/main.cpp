#include "problems/problem#1976.cpp"
#include "utils/disjoint-set.cpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <queue>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <vector>
// #include problems from 'problems' folder and test here

using namespace std;

int main() {
  vector<vector<int>> road = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                              {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                              {0, 4, 5}, {4, 6, 2}};
  printf("%d\n", solution1976::countPaths(7, road));
  return 0;
}
