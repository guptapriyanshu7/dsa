#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& prices) {
  if (prices.size() == 1) return 0;
  for (size_t i = prices.size() - 1; i > 0; i--) {
    prices[i] -= prices[i - 1];
  }
  auto gmax = prices[1], lmax = prices[1];
  for (size_t i = 2; i < prices.size(); i++) {
    if (lmax > 0) lmax += prices[i];
    else lmax = prices[i];
    gmax = max(gmax, lmax);
  }
  return max(gmax, 0);
}

int main() {
  vector<int> prices{ 7, 6, 4, 3, 1 };
  cout << solve(prices);
  return 0;
}