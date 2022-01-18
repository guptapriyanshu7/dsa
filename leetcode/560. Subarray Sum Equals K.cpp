#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums, int k) {
  auto res = 0, sum = 0;
  unordered_map<int, int> mp;
  mp.insert({ 0, 1 });
  for (auto&& i: nums) {
    sum += i;
    if (mp.count(sum - k) != 0)
      res += mp[sum - k];
    mp[sum]++;
  }
  return res;
}

int main() {
  vector<int> nums{ 1, -1, 0 };
  cout << solve(nums, 0);
  return 0;
}

// 1 2 3, k = 5
// 2 3
// 1 3 6