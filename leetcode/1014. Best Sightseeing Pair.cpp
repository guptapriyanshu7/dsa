#include <bits/stdc++.h>

using namespace std;

int solve(const vector<int>& nums) {
  auto sum = 0, res = 0;
  for (int num: nums) {
    res = max(res, sum + num);
    sum = max(sum, num) - 1;
  }
  return res;
}

int main() {
  vector<int> nums{ 8, 1, 5, 2, 6 };
  solve(nums);
  return 0;
}