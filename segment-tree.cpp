#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
int t[(4 * 131072) + 1];    //t = segment-tree
void build(int a[], int v, int tl, int tr, int x) {                                                     //t[1]
    if (tl == tr) {                                                                     //t[2]                            t[3]
        t[v] = a[tl];                                                               //t[4]   t[5]                 t[6]           t[7]
    } else {                                                                //t[8]    t[9]  t[10]  t[11]       t[12] t[13]    t[14] t[15]
        int tm = (tl + tr) / 2;                                      //notice all left elements are even and all right are odd
        build(a, v * 2, tl, tm, x - 1);                                   //in segment tree we divide the array in two halves then again in two halves....
        build(a, v * 2 + 1, tm + 1, tr, x - 1);                             //.... then again and so on until 1 element is left to store in tree
        if (x & 1) {
            t[v] = t[v * 2] | t[v * 2 + 1];
        } else {
            t[v] = t[v * 2] ^ t[v * 2 + 1];
        }
    }
}
void update(int v, int tl, int tr, int pos, int new_val, int x) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, new_val, x - 1);
        else
            update(v * 2 + 1, tm + 1, tr, pos, new_val, x - 1);
        if (x & 1) {
            t[v] = t[v * 2] | t[v * 2 + 1];
        } else {
            t[v] = t[v * 2] ^ t[v * 2 + 1];
        }
    }
}
void solve() {
    int n, m, p, b, v;
    cin >> n >> m;
    int len = 1 << n;
    int a[len];
    rep(i, len) cin >> a[i];
    build(a, 1, 0, len - 1, n);
    rep(i, m) {
        cin >> p >> b;
        update(1, 0, len - 1, p - 1, b, n);
        cout << t[1] << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();
    cerr << "\ntime taken : " << ((float)clock() / CLOCKS_PER_SEC) * 1000 << " ms\n";
    return 0;
}
//sample input
// 2 4
// 1 6 3 5
// 1 4
// 3 4
// 1 2
// 1 2
//https://cp-algorithms.com/data_structures/segment_tree.html