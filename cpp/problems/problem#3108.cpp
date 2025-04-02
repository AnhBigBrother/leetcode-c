#include "../utils/disjoint-set.cpp"
#include <vector>

using namespace std;

vector<int> minimumCost(int n, vector<vector<int>> &edges,
                        vector<vector<int>> &query) {
  DisjointSet *ds = new DisjointSet(n);
  for (int i = 0; i < edges.size(); i++) {
    ds->Union(edges[i][0], edges[i][1]);
  }
  int *weight = new int[n];
  for (int i = 0; i < n; i++) {
    weight[i] = -1;
  }
  for (int i = 0; i < edges.size(); i++) {
    int x = ds->Find(edges[i][0]);
    if (weight[x] == -1) {
      weight[x] = edges[i][2];
    } else {
      weight[x] &= edges[i][2];
    }
  }

  vector<int> ans;
  for (int i = 0; i < query.size(); i++) {
    int x = ds->Find(query[i][0]), y = ds->Find(query[i][1]);
    if (x == y) {
      ans.push_back(weight[x]);
    } else {
      ans.push_back(-1);
    }
  }
  delete[] weight;
  delete ds;
  return ans;
}
