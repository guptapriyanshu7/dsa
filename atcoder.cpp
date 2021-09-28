#include <bits/stdc++.h>

#define int long long
#define rep(x, u) for (int x = 0; x < u; x++)
#define pb        push_back
#define mp        make_pair
#define ff        first
#define ss        second
#define mod       1000000007

using namespace std;

int power(int a, int e) {
  int pow = 1;
  while (e) {
    if (e % 2)
      pow = (pow * a) % mod;
    e = e / 2;
    a = (a * a) % mod;
  }
  return pow;
}

void solve() {
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << "\n";
  }
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}