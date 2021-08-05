#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int a, b, cost;
};

int n, m;
vector<Edge> edges;
const int INF = 1000000000;

void solve() {
	vector<int> d(n);
	int x;
	for (int i = 0; i < n; ++i) {
		x = -1;
		for (Edge e : edges) {
			if (d[e.a] + e.cost < d[e.b]) {
				d[e.b] = d[e.a] + e.cost;
				x = e.b;
			}
		}
	}

	if (x == -1) {
		cout << "0";
	} else {
		cout << "1";
	}
}

int main() {
	cin >> n >> m;
	edges.resize(m);
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edges[i].a = x - 1;
		edges[i].b = y - 1;
		edges[i].cost = w;
	}
	solve();
}