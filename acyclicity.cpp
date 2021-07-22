#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<vector<int>> adj;
vector<string> color;

bool DFS(int v) {
  color[v] = "gray";
  for (int u : adj[v]) {
    if (color[u] == "gray")
      return true;
    if (color[u] == "white" && DFS(u))
      return true;
  }
  color[v] = "black";
  return false;
}

int acyclic() {
  color.assign(V, "white");
  for (int i = 0; i < V; i++) {
    if (color[i] == "white" && DFS(i))
      return 1;
  }
  return 0;
}

int main() {
  int x, y;
  cin >> V >> E;
  adj.resize(V);
  for (int i = 0; i < E; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  cout << acyclic();
}