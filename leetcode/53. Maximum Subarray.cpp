#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int global_max = INT_MIN, local_max = 0;
  for (size_t i = 0; i < nums.size(); i++) {
    local_max += nums[i];
    if (local_max >= global_max) {
      global_max = local_max;
    }
    if (local_max < 0) {
      local_max = 0;
    }
  }
  return global_max;
}

int main() {
  vector<int> nums{ -2,1,-3,4,-1,2,1,-5,4 };
  solve(nums);
  return 0;
}