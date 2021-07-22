
// #include <stdio.h>

// unsigned min(unsigned a, unsigned b) {
//   if (a < b)
//     return a;
//   else return b;
// }

// unsigned getNthUglyNo(unsigned n)
// {

//   unsigned ugly[n];
//   unsigned i2 = 0, i3 = 0, i5 = 0;
//   unsigned next_multiple_of_2 = 2;
//   unsigned next_multiple_of_3 = 3;
//   unsigned next_multiple_of_5 = 5;
//   unsigned next_ugly_no = 1;

//   ugly[0] = 1;
//   for (int i = 1; i < n; i++) {
//     next_ugly_no = min(
//       next_multiple_of_2,
//       min(next_multiple_of_3, next_multiple_of_5));
//     ugly[i] = next_ugly_no;
//     if (next_ugly_no == next_multiple_of_2) {
//       i2 = i2 + 1;
//       next_multiple_of_2 = ugly[i2] * 2;
//     }
//     if (next_ugly_no == next_multiple_of_3) {
//       i3 = i3 + 1;
//       next_multiple_of_3 = ugly[i3] * 3;
//     }
//     if (next_ugly_no == next_multiple_of_5) {
//       i5 = i5 + 1;
//       next_multiple_of_5 = ugly[i5] * 5;
//     }
//   }

//   return next_ugly_no;
// }

// int main()
// {
//   int n;
//   scanf("%d", &n);
//   printf("%d", getNthUglyNo(n));
//   return 0;
// }
#include<bits/stdc++.h>
#define in(n,arr) for(int i=0;i<n;i++) cin>>arr[i]
#define out(n,arr) for(int i=0;i<n;i++) cout<<arr[i]<<" "
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define ff first
#define ss second
#define pll pair<ll,ll>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

void rod(vector<ll>length, vector<ll>price, ll n)
{

  ll dp[n + 1][n + 1];
  loop(i, 0, n + 1)dp[0][i] = 0;
  loop(i, 0, n + 1)dp[i][0] = 0;
  ll i, j;
  loop(i, 1, n + 1)
  {
    loop(j, 1, n + 1)
    {
      if (length[i - 1] <= j)dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
      else dp[i][j] = dp[i - 1][j];
    }
  }
  ll x = n, y = n;
  cout << dp[n][n] << endl;
  ll b[2][n];
  for (i = 0;i < n;i++) { b[0][i] = i + 1;b[1][i] = 0; }
  while (x > 0 && y > 0)
  {
    if (dp[x][y] == dp[x - 1][y])x--;
    else if (dp[x - 1][y] >= dp[x][y - length[x - 1]] + price[x - 1])x--;
    else
    {
      b[1][length[x - 1]]++;
      y -= length[x - 1];
    }
  }
  for (i = 0;i < n;i++)
  {
    if (b[1][i] != 0)
    {
      cout << b[0][i] - 1 << " " << b[1][i] << endl;
    }
  }
  cout << endl;
}

void solve()
{
  ll n;
  cin >> n;
  vector<ll>length, price;
  ll i, j;
  for (i = 0;i < n;i++)
  {
    length.pb(i + 1);
  }
  for (i = 0;i < n;i++)
  {
    cin >> j;
    price.pb(j);
  }
  rod(length, price, n);

}

int main()
{
  solve();
  return 0;
}