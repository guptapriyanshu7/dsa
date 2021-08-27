#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int p1, p2;
  for (p1 = 0; p1 < nums.size() - 1; p1++) {
    if (nums[p1] > nums[p1 + 1]) break;
  }
  for (p2 = nums.size() - 1; p2 > 0; p2--) {
    if (nums[p2] < nums[p2 - 1]) break;
  }
  cout << p1 << " " << p2;
  return p2 <= p1 ? 0 : p2 - p1 + 1;
}

int main() {
  vector<int> nums{ 1,2,0 };
  cout << solve(nums);
  return 0;
}