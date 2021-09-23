#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int sum = 0, gsum = 0, n = nums.size();
  for (size_t i = 0; i < n - 1; i++) {
    if (nums[i] < nums[i + 1])
      sum += nums[i];
    else {
      gsum = max(gsum, sum + nums[i]);
      sum = 0;
    }
  }
  if (sum != 0)
    sum += nums[n - 1];
  return n == 1 ? nums[0] : max(gsum, sum);
}

int main() {
  vector<int> nums{ 50 };
  solve(nums);
  return 0;
}