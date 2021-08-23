#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& nums) {
  int p = 0;
  for (size_t i = 0; i < nums.size(); i++) {
    if (nums[i] == 0) {
      while (p < nums.size() && nums[p] == 0) p++;
      if (p >= nums.size()) return;
      swap(nums[i], nums[p]);
    }
    p++;
  }
}

int main() {
  vector<int> nums{ 0,0,0,0,12 };
  solve(nums);
  for (auto&& i : nums) {
    cout << i << " ";
  }
  return 0;
}