#include <bits/stdc++.h>

using namespace std;

bool recurse(int i, vector<int>& nums, vector<int>& memo) {
  if (memo[i] != -1) return memo[i];
  auto res = false;
  for (size_t j = 1; j <= nums[i] && i + j < nums.size(); j++) {
    if (memo[i + j] == -1) memo[i + j] = recurse(i + j, nums, memo);
    res |= memo[i + j];
    if (res) return true;
  }
  return memo[i] = res;
}

bool solve(vector<int>& nums) {
  auto n = nums.size();
  vector<int> memo(n, -1);
  memo[n - 1] = 1;
  return recurse(0, nums, memo);
}

int main() {
  vector<int> nums{ 3,2,1,0,4 };
  cout << solve(nums);
  return 0;
}