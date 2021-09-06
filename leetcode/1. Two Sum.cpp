#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& nums, int target) {
  unordered_map<int, int> m;
  for (int i = 0; i < nums.size() - 1; i++) {
    int to_find = target - nums[i];
    if (m.count(to_find) && m[to_find] != i)
      return { i, m[to_find] };
    m[nums[i]] = i;
  }
  return {};
}

int main() {
  vector<int> nums{ 2,7,11,15 };
  auto v = solve(nums, 9);
  cout << v[0] << " " << v[1];
  return 0;
}