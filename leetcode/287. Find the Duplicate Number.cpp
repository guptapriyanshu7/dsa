#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  while (nums[0] != nums[nums[0]])
    swap(nums[0], nums[nums[0]]);
  return nums[0];
}

int main() {
  vector<int> nums{ 2, 3, 4, 1, 2 };
  cout << solve(nums);
  return 0;
}