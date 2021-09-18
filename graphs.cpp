#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;
using pii = pair<int, int>;

void dfsUtil(int v, vector<int> graph[], vector<bool>& visited) {
  visited[v] = true;
  cout << v << ' ';
  for (auto u : graph[v]) {
    if (!visited[u]) {
      dfsUtil(u, graph, visited);
    }
  }
}

void dfs(vector<int> graph[], int V) {
  vector<bool> visited(V, false);
  for (size_t v = 0; v < V; v++) {
    if (!visited[v]) {
      dfsUtil(v, graph, visited);
    }
  }
}

void bfsUtil(int v, vector<int> graph[], vector<bool>& visited) {
  queue<int> q;
  visited[v] = true;
  cout << v << ' ';
  q.push(v);
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (auto u : graph[v]) {
      if (!visited[u]) {
        visited[u] = true;
        cout << u << ' ';
        q.push(u);
      }
    }
  }
}

void bfs(vector<int> graph[], int V) {
  vector<bool> visited(V, false);
  for (size_t v = 0; v < V; v++) {
    if (!visited[v]) {
      bfsUtil(v, graph, visited);
    }
  }
}

void dijkstra(int src, vector<pii> graph[], int V) {
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({ 0, src });
  while (!pq.empty()) {
    int d_u, u;
    tie(d_u, u) = pq.top();
    pq.pop();
    if (d_u != dist[u])
      continue;
    for (auto edge : graph[u]) {
      int v, weight;
      tie(v, weight) = edge;
      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pq.push({ dist[v], v });
      }
    }
  }
  cout << '\n';
  for (auto i : dist) {
    cout << i << '\n';
  }
}

// for directed graph, note we are not passing graph but edges and weights, i.e. it is always treated as directed
void bellmanFord(int src, pii edges[], vector<int> weights, int V, int E) {
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;
  int flag  = 0;
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < E; j++) {
      if (dist[edges[j].first] != INT_MAX && dist[edges[j].first] + weights[j] < dist[edges[j].second]) {
        dist[edges[j].second] = dist[edges[j].first] + weights[j];
        if (i == V - 1)
          flag = 1;
      }
    }
  }
  cout << '\n';
  if (flag) {
    cout << "Negative cycle found";
    return;
  }
  for (auto i : dist) {
    cout << i << '\n';
  }
}

// for directed and undirected graph with positive edges
void floydWarshall(vector<pii> graph[], int V) {
  int dist[V][V];
  for (int i = 0; i < V; i++)
    for (int j = 0; j < V; j++)
      dist[i][j] = INT_MAX;
  for (int v = 0; v < V; v++) {
    dist[v][v] = 0;
    for (auto edge : graph[v])
      dist[v][edge.first] = edge.second;
  }
  for (int k = 0; k < V; k++) {
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  cout << '\n';
  for (int i = 0; i < V; i++) {
    if (dist[i][i] < 0) {
      cout << "Negative cycle found" << '\n';
      return;
    }
  }
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      cout << dist[i][j] << ' ';
    cout << '\n';
  }
}

void prim(vector<pii> graph[], int V) {
  int total_weight = 0;
  vector<pii> min_e(V, { -1, INT_MAX });  // pair (parent, weight)
  min_e[0].second = 0;
  set<pii> q;  // pair (weight, current vertex)
  q.insert({ 0, 0 });
  vector<bool> selected(V, false);
  cout << '\n';
  for (int i = 0; i < V; i++) {
    if (q.empty()) {
      cout << "No MST!";
      return;
    }
    int v       = q.begin()->second;
    selected[v] = true;
    total_weight += q.begin()->first;
    q.erase(q.begin());
    if (min_e[v].first != -1)
      cout << min_e[v].first << ' ' << v << '\n';
    for (auto edge : graph[v]) {
      if (!selected[edge.first] && edge.second < min_e[edge.first].second) {
        q.erase({ min_e[edge.first].second, edge.first });
        min_e[edge.first] = { v, edge.second };
        q.insert({ edge.second, edge.first });
      }
    }
  }
  cout << total_weight << '\n';
}

vector<int> parent, depth;

void make_set(int v) {
  parent[v] = v;
  depth[v]  = 0;
}

int find_set(int v) {
  if (v == parent[v])
    return v;
  return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (depth[a] < depth[b])
      swap(a, b);
    parent[b] = a;
    if (depth[a] == depth[b])
      depth[a]++;
  }
}

struct Edge {
  int u, v, weight;
  bool operator<(Edge& other) {
    return weight < other.weight;
  }
};

void kruskal(pii e[], vector<int> weights, int V, int E) {
  vector<Edge> edges;
  for (size_t i = 0; i < E; i++) {
    Edge edge;
    edge.u      = e[i].first;
    edge.v      = e[i].second;
    edge.weight = weights[i];
    edges.push_back(edge);
  }
  int cost = 0;
  vector<Edge> result;
  parent.resize(V);
  depth.resize(V);
  for (int i = 0; i < V; i++)
    make_set(i);
  sort(edges.begin(), edges.end());
  int i = 0;
  for (Edge e : edges) {
    if (find_set(e.u) != find_set(e.v)) {
      cost += e.weight;
      result.push_back(e);
      union_sets(e.u, e.v);
      if (i + 1 == V - 1)
        break;
      else
        i++;
    }
  }
  cout << '\n';
  for (auto e : result) {
    cout << e.u << ' ' << e.v << '\n';
  }
  cout << cost;
}

int main() {
  int V = 4, E = 4;
  // int V = 5, E = 7;
  // int V = 3, E = 3;
  vector<pii> graph[V];
  pii edges[E] = { { 0, 1 }, { 1, 3 }, { 0, 2 }, { 2, 1 } };
  vector<int> weights{ 8, 5, 2, 1 };
  // pii edges[E] = {{0, 1}, {2, 0}, {1, 2}, {1, 3}, {1, 4}, {3, 2}, {4, 3}};
  // vector<int> weights{-1, 4, 3, 2, 2, 5, -3};
  // pii edges[E] = {{0, 1}, {1, 2}, {2, 0}};
  // vector<int> weights{-1, -3, -1};
  for (size_t e = 0; e < E; e++) {
    graph[edges[e].first].push_back({ edges[e].second, weights[e] });
    graph[edges[e].second].push_back({ edges[e].first, weights[e] });
  }
  for (size_t v = 0; v < V; v++) {
    for (auto u : graph[v]) {
      cout << u.first << '(' << u.second << ')' << ' ';
    }
    cout << '\n';
  }
  dijkstra(1, graph, V);                 // for undirected and directed graph
  bellmanFord(1, edges, weights, V, E);  // for directed graph, note we are not passing graph but edges and weights, i.e. it is always treated as directed
  floydWarshall(graph, V);               // for directed and undirected graph with positive edges
  prim(graph, V);                        // undirected connected graph
  kruskal(edges, weights, V, E);         // undirected connected graph
  return 0;
}

// int main() {
//   int V = 5, E = 7;
//   vector<int> graph[V];
//   pair<int, int> edges[E] = {{0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};
//   for (size_t e = 0; e < E; e++) {
//     graph[edges[e].first].push_back(edges[e].second);
//     graph[edges[e].second].push_back(edges[e].first);
//   }
//   for (size_t v = 0; v < V; v++) {
//     for (auto u: graph[v]) {
//       cout << u << ' ';
//     }
//     cout << '\n';
//   }
//   cout << '\n';
//   dfs(graph, V);
//   cout << '\n';
//   bfs(graph, V);
//   return 0;
// }
