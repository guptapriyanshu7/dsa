#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& prices) {
  for (int i = prices.size() - 1; i >= 1; i--) {
    prices[i] -= prices[i - 1];
  }
  int global_max = INT_MIN, local_max = 0;
  for (size_t i = 1; i < prices.size(); i++) {
    local_max += prices[i];
    global_max = max(local_max, global_max);
    if (local_max < 0) local_max = 0;
  }
  return global_max < 0 ? 0 : global_max;
}

int main() {
  vector<int> prices{ 7,6,4,3,1 };
  cout << solve(prices);
  return 0;
}