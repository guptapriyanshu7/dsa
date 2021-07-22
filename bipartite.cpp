#include <iostream>
#include <vector>
#include <queue>

using std::queue;
using std::vector;

bool bipartite(vector<vector<int>> &adj)
{
  int n = adj.size();
  vector<int> side(n, -1);
  bool is_bipartite = true;
  queue<int> q;
  for (int st = 0; st < n; ++st)
  {
    if (side[st] == -1)
    {
      q.push(st);
      side[st] = 0;
      while (!q.empty())
      {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
          if (side[u] == -1)
          {
            side[u] = side[v] ^ 1;
            q.push(u);
          }
          else
          {
            is_bipartite &= side[u] != side[v];
          }
        }
      }
    }
  }

  return is_bipartite;
}

int main()
{
  int n, m;
  std::cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << (bipartite(adj) ? 1 : 0);
}
