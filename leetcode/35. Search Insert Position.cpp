#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums, int target) {
  int left = 0, right = nums.size();
  while (left < right) {
    int mid = (left + right) / 2;
    if (nums[mid] == target)
      return mid;
    else if (nums[mid] < target)
      left = mid;
    else right = mid;
  }
  return 100;
}

int main() {
  vector<int> nums{ 1,3,5,6 };
  cout << solve(nums, 7);
  return 0;
}