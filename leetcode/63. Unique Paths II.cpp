#include <bits/stdc++.h>

using namespace std;

int recurse(int i, int j, const vector<vector<int>>& nums, vector<vector<int>>& dp) {
  auto m = nums.size(), n = nums[0].size();
  if (i == m || j == n) return 0;
  if (nums[i][j]) return 0;
  if (i == m - 1 && j == n - 1) return 1;
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = recurse(i + 1, j, nums, dp) + recurse(i, j + 1, nums, dp);
}

int solve(const vector<vector<int>>& nums) {
  auto m = nums.size(), n = nums[0].size();
  vector<vector<int>> dp(m, vector<int>(n, -1));
  return recurse(0, 0, nums, dp);
}

int main() {
  vector<vector<int>> nums{ { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
  cout << solve(nums);
  return 0;
}