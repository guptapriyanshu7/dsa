#include <iostream>
#include <cstring>

using namespace std;

int recurse(int length, int limit, int weights[], int values[], int dp[]) {
  if(dp[limit] != -1) {
    return dp[limit];
  }
  int m = 0;
  for (size_t idx = 0; idx < length; idx++) {
    int taken = weights[idx];
    if(taken <= limit) {
      m = max(values[idx] + recurse(length, limit - taken, weights, values, dp), m);
    }
  }
  dp[limit] = m;
  return dp[limit];
}

int main() {
  int weights[] = {5, 10, 15};
  int values[] = {10, 30, 20};
  int limit = 100;
  int n = sizeof(weights) / sizeof(weights[0]);
  int dp[limit + 1];
  memset(dp, -1, sizeof(dp));
  cout << recurse(n, limit, weights, values, dp);
  return 0;
}

// #include <iostream>
// #include <cstring>

// using namespace std;
// int a = 0;

// int recurse(int idx, int limit, int weights[], int values[], int dp[][101]) {
//   if(idx == -1 || limit == 0) {
//     return 0;
//   }
//   if(dp[idx][limit] != -1) {
//     return dp[idx][limit];
//   }
//   a++;
//   int taken = weights[idx];
//   if(taken > limit) {
//     return dp[idx][limit] = recurse(idx - 1, limit, weights, values, dp);
//   } 
//   return dp[idx][limit] =  m(values[idx] + recurse(idx, limit - taken, weights, values, dp), recurse(idx - 1, limit, weights, values, dp));
// }

// int main() {
//   int weights[] = {5, 10, 15};
//   int values[] = {10, 30, 20};
//   int limit = 100;
//   int n = sizeof(weights) / sizeof(weights[0]);
//   int dp[n][101];
//   memset(dp, -1, sizeof(dp));
//   cout << recurse(n - 1, limit, weights, values, dp);
//   // cout << " " << a;
//   // for (size_t i = 0; i < limit + 1; i++) {
//   //   cout << dp[i] << ' ';
//   // }
//   return 0;
// }