#include <iostream>
#include <queue>
#include <vector>

using std::queue;
using std::vector;

int distance(vector<vector<int>>& adj, int s, int t) {
  int n = adj.size();
  queue<int> q;
  vector<bool> used(n);
  vector<int> d(n);
  d.assign(n, -1);
  q.push(s);
  used[s] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : adj[v]) {
      if (!used[u]) {
        used[u] = true;
        q.push(u);
        d[u] = d[v] + 1;
      }
    }
  }
  return d[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
