
class DisjointSet {
private:
  int *ds;

public:
  DisjointSet(int n) {
    ds = new int[n];
    for (int i = 0; i < n; i++) {
      ds[i] = i;
    }
  }
  ~DisjointSet() { delete[] ds; }

  int Find(int x) {
    int parent = ds[x];
    if (parent == x) {
      return x;
    }
    return Find(parent);
  }
  void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);
    if (px < py) {
      ds[py] = px;
    } else {
      ds[px] = py;
    }
  }
  bool Check(int x, int y) { return Find(x) == Find(y); }
};
