#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int mod = 1000000007;
  vector<long long> dp(nums.size(), -1);
  dp[0] = 2;
  for (size_t i = 1; i < nums.size() - 1; i++) {
    if (dp[nums[i]] != -1) {
      if (nums[i] - 1 == -1)
        dp[i] = dp[i - 1] + 1 + dp[i - 1] + 1;
      else  dp[i] = dp[i - 1] + 1 + dp[i - 1] + 1 - dp[nums[i] - 1];
    } else {
      dp[i] = dp[i - 1] + 2;
    }
    dp[i] = (dp[i] + mod) % mod;
    cout << dp[i] << " ";
  }
  return dp[nums.size() - 2];
}

int main() {
  vector<int> nums{ 0,0,0,0,0,0,0,0,0,9,1,8 };
  cout << solve(nums);
  return 0;
}

// dp[0] = days req to go to 1
// dp[1] = days req to go to 2
//          :
//          :
// dp[n - 2] = days req to go to n - 1
// if i = nums[i], i.e. 1 = nums[1], then dp[1] = 2 + dp[0];
// base case dp[0] = 2