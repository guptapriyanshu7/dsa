#include <iostream>
#include <queue>
#include <vector>

using std::pair;
using std::priority_queue;
using std::queue;
using std::vector;
const int INF = 1000000000;

int dijkstra(vector<vector<pair<int, int>>>& adj, int s, int t) {

  int n = adj.size();
  vector<int> d(n);
  d.assign(n, INF);
  vector<bool> u(n, false);

  d[s] = 0;
  for (int i = 0; i < n; i++) {
    int v = -1;
    for (int j = 0; j < n; j++) {
      if (!u[j] && (v == -1 || d[j] < d[v]))
        v = j;
    }

    if (d[v] == INF)
      continue;

    u[v] = true;
    for (auto edge : adj[v]) {
      int to  = edge.first;
      int len = edge.second;

      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
      }
    }
  }
  if (d[t] == INF)
    d[t] = -1;
  return d[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<pair<int, int>>> adj;
  adj.resize(n);
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(std::make_pair(y - 1, w));
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << dijkstra(adj, s, t);
}
