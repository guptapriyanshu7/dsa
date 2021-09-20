#include <bits/stdc++.h>

using namespace std;

// int recurse(int i, int j, int x, const vector<int>& nums, vector<vector<int>>& dp) {
//   if (x == 0) return 0;
//   if (i == j + 1 || x < 0) return 1e8;
//   if (dp[i][j] != -1) return dp[i][j];
//   return dp[i][j] = 1 + min(recurse(i + 1, j, x - nums[i], nums, dp), recurse(i, j - 1, x - nums[j], nums, dp));
// }

// int solve(vector<int>& nums, int x) {
//   vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
//   auto res = recurse(0, nums.size() - 1, x, nums, dp);
//   return res < 1e8 ? res : -1;
// }
// }

int solve(vector<int>& nums, int x) {
  auto res = 0, cum = 0, target = -x;
  for (int num: nums) target += num;
  if (target == 0) return nums.size();
  unordered_map<int, int> unm;
  unm[0] = -1;
  for (int i = 0; i < nums.size(); i++) {
    cum += nums[i];
    auto req = cum - target;
    if (unm.count(req)) res = max(res, i - unm[req]);
    unm[cum] = i;
  }
  return res == 0 ? -1 : nums.size() - res;
}

int main() {
  vector<int> nums{ 1, 1, 4, 2, 3 };
  cout << solve(nums, 5);
  return 0;
}