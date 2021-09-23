#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  auto m = nums[0];
  for (size_t i = 1; i < nums.size(); i++) {
    nums[i] += nums[i - 1];
    m = min(m, nums[i]);
  }
  if (m < 0) return -m + 1;
  else return 1;
}

int main() {
  vector<int> nums{ 3, -4, 1 };
  cout << solve(nums);
  return 0;
}