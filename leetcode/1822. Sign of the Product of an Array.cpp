#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int count = 0;
  for (auto i : nums) {
    if (i == 0)
      return 0;
    else if (i < 0)
      count++;
  }
  return (count % 2 == 0) ? 1 : -1;
}

int main() {
  vector<int> nums{1,5,0,2,-3};
  cout << solve(nums);
  return 0;
}