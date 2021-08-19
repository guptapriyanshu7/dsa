#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& nums, int target) {
  unordered_map<int, int> m;
  for (size_t i = 0; i < nums.size(); i++) {
    m[nums[i]] = i;
  }
  vector<int> a(2);
  for (int i = 0; i < nums.size(); i++) {
    int to_find = target - nums[i];
    if (m.find(to_find) != m.end() && m[to_find] != i) {
      a[0] = i;
      a[1] = m[to_find];
      cout << a[0] << a[1];
      return a;
    }
  }
  return a;
}

int main() {
  vector<int> nums{ 2,7,11,15 };
  int target = 9;
  solve(nums, target);
  return 0;
}