#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums) {
  auto n = nums.size(), i = n - 1;
  while (i > 0) {
    if (nums[i - 1] < nums[i]) break;
    i--;
  }
  if (i > 0) {
    for (size_t k = n - 1; k >= i; k--) {
      if (nums[i - 1] < nums[k]) {
        swap(nums[i - 1], nums[k]);
        break;
      }
    }
  }
  for (size_t k = i; k < i + (n - i) / 2; k++) {
    swap(nums[k], nums[n - 1 - (k - i)]);
  }
}

int main() {
  vector<int> nums{ 1 };
  solve(nums);
  for (auto&& i: nums)
    cout << i << " ";
  return 0;
}