#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  unordered_set<int> s;
  for (auto num: nums) s.insert(num);
  auto res = 0;
  for (auto num: nums) {
    auto loc = 0;
    if (s.count(num - 1) == 0)
      while (s.count(num++) != 0) loc++;
    res = max(res, loc);
  }
  return res;
}

int main() {
  vector<int> nums{ 100, 4, 200, 1, 3, 2 };
  cout << solve(nums);
  return 0;
}