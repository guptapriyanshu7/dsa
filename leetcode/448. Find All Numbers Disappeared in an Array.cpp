#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& nums) {
  int len = nums.size();
  for (int i = 0; i < len; i++) {
    int m = abs(nums[i]) - 1;
    nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
  }
  vector<int> res;
  for (int i = 0; i < len; i++) {
    if (nums[i] > 0) res.push_back(i + 1);
  }
  return res;
}

int main() {
  vector<int> nums{ 5,3,3,2,5 };
  solve(nums);
  return 0;
}