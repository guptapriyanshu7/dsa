#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  auto ans = nums[0], cnt = 1;
  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[i] == ans) cnt++;
    else cnt--;
    if (cnt == 0) ans = nums[i], cnt = 1;
  }
  return ans;
}

int main() {
  vector<int> nums{ 2, 2, 1, 1, 1, 2, 2 };
  cout << solve(nums);
  return 0;
}