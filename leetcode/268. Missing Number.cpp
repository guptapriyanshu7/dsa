#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int sum = 0, n = nums.size();
  for (auto&& i : nums) sum += i;
  int req = n * (n + 1) / 2;
  return req - sum;
}

int main() {
  vector<int> nums{ 3,0,1 };
  cout << solve(nums);
  return 0;
}