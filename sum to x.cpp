#include <bits/stdc++.h>
#define int long long
using namespace std;

bool solve(vector<int>& ph, int x, int i, vector<vector<int>>& mem) {
  if (i == ph.size() || x < 0) return false;
  if (x == ph[i]) return true;
  if (mem[i][x] != -1) return mem[i][x];
  return mem[i][x] = solve(ph, x - ph[i], i + 1, mem) || solve(ph, x, i + 1, mem);
}

signed main() {
  int n, q;
  cin >> n >> q;
  vector<int> h(n), ph;
  for (size_t i = 0; i < n; i++) cin >> h[i];
  vector<int> primes(n + 1, true);
  primes[0] = primes[1] = false;
  for (size_t i = 2; i * i <= n; i++) {
    for (size_t j = i * i; j <= n; j += i) {
      primes[j] = false;
    }
  }
  for (size_t i = 1; i <= n; i++) {
    if (primes[i]) {
      ph.push_back(h[i - 1]);
    }
  }
  while (q--) {
    int x;
    cin >> x;
    vector<vector<int>> mem(ph.size(), vector<int>(100, -1));
    cout << (solve(ph, x, 0, mem) ? "YES\n" : "NO\n");
  }
  return 0;
}
