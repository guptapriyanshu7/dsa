#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

vector<bool> visited;
vector<int> ans;

void dfs(int v, vector<vector<int>> &adj) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u, adj);
    }
    ans.push_back(v);
}

vector<int> topological_sort(vector<vector<int>> &adj) {
    visited.assign(adj.size(), false);
    ans.clear();
    for (int i = 0; i < adj.size(); ++i) {
        if (!visited[i])
            dfs(i, adj);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  vector<int> order = topological_sort(adj);
  for (size_t i = 0; i < order.size(); i++) {
    std::cout << order[i] + 1 << " ";
  }
}
