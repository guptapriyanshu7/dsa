#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int m = 0, l = 0, r = nums.size() - 1;
  while (l < r) {
    int area = min(nums[l], nums[r]) * (r - l);
    m        = max(m, area);
    nums[l] < nums[r] ? l++ : r--;
  }
  return m;
}

int main() {
  vector<int> nums{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
  cout << solve(nums);
  return 0;
}