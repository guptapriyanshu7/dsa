#include<bits/stdc++.h>
#define FOR(x,u) for(int x=0;x<u;x++)
typedef long long ll;
using namespace std;
void solve() {
    int b = 3, c = 2;
    int a = ceil((double)b / c);
    cout << a;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //#endif 
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
        cout << "\n";
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}