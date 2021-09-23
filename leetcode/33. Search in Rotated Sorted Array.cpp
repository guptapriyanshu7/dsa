#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums, int target) {
  int l = 0, r = nums.size();
  while (l < r) {
    int mid = l + (r - l) / 2;
    int num = (nums[mid] < nums[0]) == (target < nums[0]) ? nums[mid]
              : target < nums[0]                          ? INT_MIN
                                                          : INT_MAX;
    if (num == target)
      return mid;
    else if (num < target)
      l = mid + 1;
    else
      r = mid;
  }
  return -1;
}

int main() {
  vector<int> nums{ 1, 3 };
  cout << solve(nums, 3);
  return 0;
}