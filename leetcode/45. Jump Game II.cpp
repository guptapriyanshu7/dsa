#include <bits/stdc++.h>

using namespace std;

int recurse(int i, const vector<int>& nums, vector<int>& dp) {
  if (i >= nums.size() - 1) return 0;
  if (dp[i] != -1) return dp[i];
  auto res = INT_MAX - 1;
  for (size_t j = 1; j <= nums[i]; j++) {
    res = min(res, 1 + recurse(i + j, nums, dp));
  }
  return dp[i] = res;
}

int solve(const vector<int>& nums) {
  vector<int> dp(nums.size(), -1);
  return recurse(0, nums, dp);
}

int main() {
  vector<int> nums{ 2, 3, 1, 1, 4 };
  cout << solve(nums);
  return 0;
}