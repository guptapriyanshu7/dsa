#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int count = 0;
  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[i] == nums[i - 1])
      count++;
    else
      nums[i - count] = nums[i];
  }
  return nums.size() - count;
}

int main() {
  vector<int> nums{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 5 };
  cout << solve(nums);
  for (auto&& i : nums) { cout << i << " "; }
  return 0;
}