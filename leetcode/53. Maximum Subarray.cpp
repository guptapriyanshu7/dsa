#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  auto gmax = nums[0], lmax = nums[0];
  for (size_t i = 1; i < nums.size(); i++) {
    if (lmax > 0) lmax += nums[i];
    else lmax = nums[i];
    if (lmax > gmax) {
      gmax = lmax;
    }
  }
  return gmax;
}

int main() {
  vector<int> nums{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  solve(nums);
  return 0;
}