#include <bits/stdc++.h>

using namespace std;

int recurse(vector<int>& nums, int i, int j, int sum, vector<vector<int>>& dp) {
  if (i == j) return nums[i];
  if (dp[i][j] != -1) return dp[i][j];
  return dp[i][j] = max(sum - recurse(nums, i + 1, j, sum - nums[i], dp),
    sum - recurse(nums, i, j - 1, sum - nums[j], dp));
}

int solve(vector<int>& nums) {
  vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
  auto sum = accumulate(nums.begin(), nums.end(), 0),
    player1 = recurse(nums, 0, nums.size() - 1, sum, dp);
  return player1 >= sum - player1;
}

int main() {
  vector<int> nums{ 1,5,233,7 };
  cout << solve(nums);
  return 0;
}

/*
1 5 233 7

a 1 233
b 7 5

a 7 5
b 233 1
*/