#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int c = 0, m;
  for (auto&& num : nums) {
    if (c == 0) m = num;
    m == num ? c++ : c--;
  }
  return m;
}

int main() {
  vector<int> nums{ 7, 7, 7, 5, 1, 1, 7 };
  cout << solve(nums);
  return 0;
}