#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  auto res = 0;
  vector<int> nums(n + 1);
  nums[0] = 0;
  if (n > 0) nums[1] = 1;
  for (size_t i = 1; 2 * i <= n; i++) {
    nums[2 * i] = nums[i];
    if (2 * i + 1 <= n) nums[2 * i + 1] = nums[i] + nums[i + 1];
  }
  for (auto&& i: nums)
    res = max(res, i);
  return res;
}

int main() {
  cout << solve(10);
  return 0;
}