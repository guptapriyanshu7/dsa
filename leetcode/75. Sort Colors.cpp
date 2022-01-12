#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums) {
  size_t zero = 0, one = 0, two = 0, k = 0;
  for (auto&& i: nums) {
    if (i == 0) zero++;
    else if (i == 1) one++;
    else two++;
  }
  for (; zero > 0; zero--, k++) nums[k] = 0;
  for (; one > 0; one--, k++) nums[k] = 1;
  for (; two > 0; two--, k++) nums[k] = 2;
}

int main() {
  vector<int> nums{ 2, 0, 2, 1, 1, 0 };
  solve(nums);
  for (auto&& i: nums)
    cout << i << " ";
  return 0;
}