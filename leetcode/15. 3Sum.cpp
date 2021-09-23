#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(vector<int>& nums) {
  if (nums.size() < 3) return {};
  sort(nums.begin(), nums.end());
  unordered_map<int, int> m;
  vector<vector<int>> s;
  for (size_t i = 0; i < nums.size(); i++) m[nums[i]] = i;
  for (size_t k = 0; k < nums.size() - 2; k++) {
    if (nums[k] > 0) break;
    if (k > 0 && nums[k] == nums[k - 1]) continue;
    for (size_t i = k + 1; i < nums.size() - 1; i++) {
      if (i > k + 1 && nums[i] == nums[i - 1]) continue;
      int to_find = -nums[k] - nums[i];
      if (m.count(to_find) && i < m[to_find])
        s.push_back({ nums[i], to_find, nums[k] });
    }
  }
  return s;
}

int main() {
  vector<int> nums{ -1, 0, 1, 2, -1, -4 };
  auto ans = solve(nums);
  for (size_t i = 0; i < ans.size(); i++) {
    for (size_t j = 0; j < 3; j++) cout << ans[i][j] << " ";
    cout << "\n";
  }
  return 0;
}