#include <bits/stdc++.h>

using namespace std;

bool solve(vector<vector<int>>& nums, int target) {
  int l = 0, r = nums.size() - 1;
  while (l <= r) {
    auto m = l + (r - l) / 2;
    if (nums[m][0] == target) return true;
    if (nums[m][0] < target) l = m + 1;
    else r = m - 1;
  }
  if (l == 0) return false;
  int ll = 0, rr = nums[0].size() - 1;
  while (ll <= rr) {
    auto mm = ll + (rr - ll) / 2;
    if (nums[l - 1][mm] == target) return true;
    if (nums[l - 1][mm] < target) ll = mm + 1;
    else rr = mm - 1;
  }
  return false;
}

int main() {
  vector<vector<int>> nums{ { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
  cout << boolalpha << solve(nums, 3);
  return 0;
}