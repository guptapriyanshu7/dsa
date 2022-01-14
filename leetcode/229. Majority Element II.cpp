#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& nums) {
  auto ans1 = nums[0], cnt1 = 1;
  auto ans2 = nums[0], cnt2 = 0;
  for (size_t i = 1; i < nums.size(); i++) {
    if (nums[i] == ans1) cnt1++;
    else if (nums[i] == ans2) cnt2++;
    else if (cnt1 == 0) ans1 = nums[i], cnt1 = 1;
    else if (cnt2 == 0) ans2 = nums[i], cnt2 = 1;
    else cnt1--, cnt2--;
  }
  cnt1 = 0, cnt2 = 0;
  for (auto&& val: nums) {
    if (val == ans1) cnt1++;
    else if (val == ans2) cnt2++;
  }
  vector<int> res;
  if (cnt1 > nums.size() / 3) res.push_back(ans1);
  if (cnt2 > nums.size() / 3) res.push_back(ans2);
  return res;
}

int main() {
  vector<int> nums{ 3, 2, 3 };
  cout << solve(nums)[0];
  return 0;
}