// #include <iostream>
// #include <vector>

// using namespace std;

// int recurse(int idx, int limit, int weights[], int values[], vector<int> dp[]) {
//   if(idx == -1 || limit == 0) {
//     return 0;
//   }
//   if(dp[idx][limit] != -1) {
//     return dp[idx][limit];
//   }
//   int taken = weights[idx];
//   if(taken > limit) {
//     return dp[idx][limit] = recurse(idx - 1, limit, weights, values, dp);
//   }
//   return dp[idx][limit] =  max(values[idx] + recurse(idx - 1, limit - taken, weights, values, dp), recurse(idx - 1, limit, weights, values, dp));
// }

// int main() {
//   int weights[] = {10, 20, 30};
//   int values[] = {60, 100, 120};
//   int limit = 50;
//   int n = sizeof(weights) / sizeof(weights[0]);
//   vector<int> dp[n];
//   for (size_t i = 0; i < n; i++) {
//     dp[i].resize(limit + 1, -1);
//   }
//   cout << recurse(n - 1, limit, weights, values, dp);
//   return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int recurse(vector<int>& weights, vector<int>& values, int i, int W, vector<vector<int>>& dp) {
  if (i == weights.size() || W == 0) return 0;
  if (dp[i][W] != -1) return dp[i][W];
  if (W < weights[i]) return dp[i][W] = recurse(weights, values, i + 1, W, dp);
  return dp[i][W] = max(values[i] + recurse(weights, values, i + 1, W - weights[i], dp),
    recurse(weights, values, i + 1, W, dp));
}

int main() {
  auto W = 50;
  vector<int> weights{ 10, 20, 30 }, values{ 60, 100, 120 };
  vector<vector<int>> dp(weights.size(), vector<int>(W + 1, -1));
  cout << recurse(weights, values, 0, W, dp);
  return 0;
}