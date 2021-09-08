#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int last = 0;
  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[i] <= nums[last])
      *lower_bound(begin(nums), begin(nums) + last, nums[i]) = nums[i];
    else nums[++last] = nums[i];
  }
  return last + 1;
}

int main() {
  vector<int> nums{ 4,10,4,3,8,9 };
  solve(nums);
  for (auto&& i : nums)
    cout << i << " ";
  return 0;
}