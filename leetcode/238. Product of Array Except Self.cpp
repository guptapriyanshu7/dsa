#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& nums) {
  auto n = nums.size();
  vector<int> ans(n);
  ans[0] = 1;
  for (size_t i = 1; i < n; i++)
    ans[i] = nums[i - 1] * ans[i - 1];
  for (int i = n - 2, right = 1; i >= 0; i--) {
    right *= nums[i + 1];
    ans[i] *= right;
  }
  return ans;
}

int main() {
  vector<int> nums{ 5, 4, 6 };
  auto res = solve(nums);
  for (auto&& i : res) cout << i << " ";
  return 0;
}

// 5 4 6    6 left 5 * 4
// 5 4 6    5 right 4 * 6