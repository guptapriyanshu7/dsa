#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int pmax, pmin, g;
  pmax = pmin = g = nums[0];
  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[i] < 0) swap(pmax, pmin);
    pmax = max(nums[i], pmax * nums[i]);
    pmin = min(nums[i], pmin * nums[i]);
    cout << pmax << " " << pmin << "\n";
    g = max(g, pmax);
  }
  return g;
}

int main() {
  vector<int> nums{ 2,3,-2,4 };
  cout << solve(nums);
  return 0;
}