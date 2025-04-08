#pragma once

class DisjointSet {
private:
  int *ds;

public:
  DisjointSet(int n);
  ~DisjointSet();

  int Find(int x);
  void Union(int x, int y);
  bool Check(int x, int y);
};
