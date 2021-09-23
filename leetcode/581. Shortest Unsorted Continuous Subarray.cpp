#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
  int p1 = nums.size() - 1, p2 = 0;
  stack<int> s;
  for (int i = 0; i < nums.size(); i++) {
    while (!s.empty() && nums[s.top()] > nums[i]) {
      p1 = min(p1, s.top());
      s.pop();
    }
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = nums.size() - 1; i >= 0; i--) {
    while (!s.empty() && nums[s.top()] < nums[i]) {
      p2 = max(p2, s.top());
      s.pop();
    }
    s.push(i);
  }
  return p2 <= p1 ? 0 : p2 - p1 + 1;
}

int main() {
  vector<int> nums{ 1,2,0 };
  cout << solve(nums);
  return 0;
}