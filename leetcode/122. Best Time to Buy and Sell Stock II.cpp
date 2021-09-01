#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& prices) {
  int sum = 0;
  for (int i = prices.size() - 1; i >= 1; i--) {
    int diff = prices[i] - prices[i - 1];
    if (diff > 0) sum += diff;
  }
  // int global_max = 0, local_max = 0;
  // for (size_t i = 1; i < prices.size(); i++) {
  //   local_max = max(prices[i], local_max + prices[i]);
  //   global_max = max(local_max, global_max);
  // }
  return sum;
}

int main() {
  vector<int> nums{ 7,1,5,3,6,4 };
  cout << solve(nums);
  return 0;
}