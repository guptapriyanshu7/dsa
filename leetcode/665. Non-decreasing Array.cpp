#include <bits/stdc++.h>

using namespace std;

bool solve(vector<int>& nums) {
  int count = 0;
  for (size_t i = 0; i < nums.size() - 1 && count <= 1; i++) {
    if (nums[i] > nums[i + 1]) {
      count++;
      if (i > 0 && nums[i - 1] > nums[i + 1]) nums[i + 1] = nums[i];
      // else nums[i] = nums[i + 1];
    }
  }
  return count <= 1;
}

int main() {
  vector<int> nums{ 3,4,2,3 };
  cout << solve(nums) << "\n";
  for (auto&& i : nums) {
    cout << i << " ";
  }
  return 0;
}