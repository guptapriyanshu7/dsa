#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
int n;
vector<vector<int>> adj;
vector<bool> visited;
void DFS(int v) {
    visited[v] = true;
    for (auto i : adj[v])
        if (!visited[i])    DFS(i);
}
int number_of_components() {
    int res = 0;
    visited.assign(n, false);
    for (int v = 0; v < n; v++)
        if (!visited[v])    DFS(v), res++;
    return res;
}
int main() {
    int m, x, y;
    cin >> n >> m;
    adj.resize(n);
    rep(i, m) {
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    cout << number_of_components();
}