#include <bits/stdc++.h>

using namespace std;

string solve(vector<string>& nums) {
  string ans = nums[0];
  for (size_t i = 1; i < nums.size(); i++) {
    string comp = nums[i], temp;
    for (size_t c = 0; c < min(comp.size(), ans.size()); c++) {
      if (ans[c] == comp[c]) {
        temp += ans[c];
      } else break;
    }
    ans = temp;
  }
  return ans;
}

int main() {
  vector<string> nums{ "dog","racecar","car" };
  cout << solve(nums);
  return 0;
}