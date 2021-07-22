#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
void solve() {
    int n, a, b;
    string s, f;
    cin >> n >> s;
    f = s;
    rep(i, f.size() - 2) {
        a = 0, b = 0;
        rep(j, 3) {
            if (f[i + j] == 'A') a++;    else b++;
        }
        if (a == 2 || b == 2) {
            f = "";
            rep(k, s.size()) {
                if (k == i) {
                    if (a == 2) f += "A";    else f += "B";
                    k += 2;
                } else    f += s[k];
            }
            i -= 2;
            if (i < -1)  i = -1;
        }
        s = f;
        if (f.size() == 1) { cout << "Y"; return; }
    }
    cout << "N";
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("alchemy_validation_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1, n;
    cin >> t;
    n = t;
    while (t--) {
        cout << "Case #" << n - t << ": ";
        solve();
        cout << "\n";
    }
    cerr << "time taken : " << ((float)clock() / CLOCKS_PER_SEC) * 1000 << " ms\n";
    return 0;
}
