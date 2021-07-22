#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
void solve()
{
    int n, k, i, j, temp, m;
    cin >> n >> k >> m;
    int a[n + 1], sum[n + 1] = {0};
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    rep(i, n)
    {
        cin >> a[i + 1];
        sum[i + 1] = sum[i] + a[i + 1];
    }                           //n - no of items available
    for(i = k; i <= n; i++)     //m - total weight (rows)(no of groups)
    {                           //k - lenght of subsequence
        temp = sum[i] - sum[i - k];    //temp - value of a weight
        for(j = 1; j <= m; j++)
            dp[i][j] = max(dp[i - k][j - 1] + temp, dp[i - 1][j]);
    }
    cout << dp[n][m];
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    solve();
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}