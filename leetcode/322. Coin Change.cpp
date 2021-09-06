#include <bits/stdc++.h>

using namespace std;

int recurse(vector<int>& nums, int i, int amount, vector<vector<int>>& mem) {
  if (i == nums.size() || amount < 0) return INT_MAX - 1;
  if (amount == nums[i]) return 1;
  if (mem[i][amount] != -1) return mem[i][amount];
  return mem[i][amount] = min(recurse(nums, i, amount - nums[i], mem) + 1, recurse(nums, i + 1, amount, mem));
}

int solve(vector<int>& nums, int amount) {
  if (amount == 0) return 0;
  vector<vector<int>> mem(nums.size(), vector<int>(amount + 1, -1));
  auto res = recurse(nums, 0, amount, mem);
  if (res == INT_MAX - 1) res = -1;
  return res;
}

int main() {
  vector<int> nums{ 1 };
  cout << solve(nums, 0);
  return 0;
}