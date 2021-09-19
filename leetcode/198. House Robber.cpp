#include <bits/stdc++.h>

using namespace std;

int recurse(int i, vector<int>& nums, vector<int>& memo) {
  if (i >= nums.size()) return 0;
  if (memo[i] != -1) return memo[i];
  memo[i] = max(recurse(i + 2, nums, memo) + nums[i], recurse(i + 1, nums, memo));
  return memo[i];
}

int solve(vector<int>& nums) {
  vector<int> memo(nums.size(), -1);
  return recurse(0, nums, memo);
}

int main() {
  vector<int> nums{ 2, 7, 9, 3, 1 };
  cout << solve(nums);
  return 0;
}