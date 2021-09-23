#include <bits/stdc++.h>

using namespace std;

bool recurse(vector<int>& nums, int x, int i, vector<vector<int>>& mem) {
  if (i == nums.size() || x < 0) return false;
  if (x == nums[i]) return true;
  if (mem[i][x] != -1) return mem[i][x];
  return mem[i][x] = recurse(nums, x - nums[i], i + 1, mem) || recurse(nums, x, i + 1, mem);
}

int solve(vector<int>& nums) {
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2) return false;
  vector<vector<int>> mem(nums.size(), vector<int>(sum / 2 + 1, -1));
  return recurse(nums, sum / 2, 0, mem);
}

int main() {
  vector<int> nums{ 1,5,11,5 };
  cout << solve(nums);
  return 0;
}