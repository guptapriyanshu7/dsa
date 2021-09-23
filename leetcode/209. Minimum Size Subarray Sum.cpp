#include <bits/stdc++.h>

using namespace std;

int solve(int target, vector<int>& nums) {
  auto l = 0, r = 0, sum = 0, m = INT_MAX;
  while (r < nums.size()) {
    sum += nums[r++];
    while (sum >= target) {
      m = min(m, r - l);
      sum -= nums[l++];
    }
  }
  return m == INT_MAX ? 0 : m;
}

int main() {
  vector<int> nums{ 2, 3, 1, 2, 4, 3 };
  cout << solve(7, nums);
  return 0;
}