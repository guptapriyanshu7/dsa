#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums, int k) {
  auto cnt = 0, cum = 0;
  unordered_multiset<int> unms;
  unms.insert(0);
  for (size_t i = 0; i < nums.size(); i++) {
    cum += nums[i];
    auto req = cum - k;
    if (unms.find(req) != unms.end())
      cnt += unms.count(req);
    unms.insert(cum);
  }
  return cnt;
}

int main() {
  vector<int> nums{ 1,-1,0 };
  cout << solve(nums, 0);
  return 0;
}

// 1 2 3, k = 5
// 2 3
// 1 3 6