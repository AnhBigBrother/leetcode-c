#include <queue>
#include <vector>

using namespace std;

namespace solution1976 {
struct Item {
  int Node;
  int Time;
  Item(int n, int t) {
    this->Node = n;
    this->Time = t;
  }
};

int countPaths(int n, vector<vector<int>> &roads) {
  int MOD = 1e9 + 7;
  vector<vector<Item>> next(n, vector<Item>());
  for (auto r : roads) {
    int u = r[0], v = r[1], time = r[2];
    next[u].push_back(Item(v, time));
    next[v].push_back(Item(u, time));
  }
  vector<int> minTime(n, 1e9 + 7);
  vector<int> count(n, 0);
  minTime[0] = 0;
  count[0] = 1;
  auto compare = [](const Item l, const Item r) { return l.Time > r.Time; };
  priority_queue<Item, vector<Item>, decltype(compare)> pq(compare);
  pq.push(Item(0, 0));
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (cur.Node == n - 1 || cur.Time > minTime[cur.Node]) {
      continue;
    }
    for (auto x : next[cur.Node]) {
      if (minTime[x.Node] > cur.Time + x.Time) {
        minTime[x.Node] = cur.Time + x.Time;
        count[x.Node] = count[cur.Node];
        pq.push(Item(x.Node, minTime[x.Node]));
      } else if (minTime[x.Node] == minTime[cur.Node] + x.Time) {
        count[x.Node] = (count[x.Node] + count[cur.Node]) % MOD;
      }
    }
  }
  return count[n - 1];
}
}; // namespace solution1976
