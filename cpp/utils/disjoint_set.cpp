#include "disjoint_set.hpp"

DisjointSet::DisjointSet(int n) {
  ds = new int[n];
  for (int i = 0; i < n; i++) {
    ds[i] = i;
  }
}
DisjointSet::~DisjointSet() { delete[] ds; }

int DisjointSet::Find(int x) {
  int parent = ds[x];
  if (parent == x) {
    return x;
  }
  return Find(parent);
}
void DisjointSet::Union(int x, int y) {
  int px = Find(x);
  int py = Find(y);
  if (px < py) {
    ds[py] = px;
  } else {
    ds[px] = py;
  }
}
bool DisjointSet::Check(int x, int y) { return Find(x) == Find(y); }
