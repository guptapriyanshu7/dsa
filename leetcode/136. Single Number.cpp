#include <bits/stdc++.h>

using namespace std;

// 0 ^ a = a
// a ^ a = 0
// a ^ b ^ a = a ^ a ^ b = 0 ^ b = b

int solve(vector<int>& nums) {
  int ans = 0;
  for (auto&& i : nums)
    ans ^= i;
  return ans;
}

int main() {
  vector<int> nums{ 1, 1, 3 };
  cout << solve(nums);
  return 0;
}