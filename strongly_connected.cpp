#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1(int v)
{
  used[v] = true;
  for (size_t i = 0; i < g[v].size(); ++i)
    if (!used[g[v][i]])
      dfs1(g[v][i]);
  order.push_back(v);
}

void dfs2(int v)
{
  used[v] = true;
  component.push_back(v + 1);
  for (size_t i = 0; i < gr[v].size(); ++i)
    if (!used[gr[v][i]])
      dfs2(gr[v][i]);
}

int main()
{
  int n, E, x, y, c = 0;
  cin >> n >> E;
  g.resize(n);
  gr.resize(n);
  for (int i = 0; i < E; i++)
  {
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    gr[y - 1].push_back(x - 1);
  }

  used.assign(n, false);
  for (int i = 0; i < n; ++i)
    if (!used[i])
      dfs1(i);
  used.assign(n, false);
  for (int i = 0; i < n; ++i)
  {
    int v = order[n - 1 - i];
    if (!used[v])
    {
      dfs2(v);
      for(int u : component)
        cout << u << " ";
      cout << "\n";
      component.clear();
      c++;
    }
  }
  cout << c;
}