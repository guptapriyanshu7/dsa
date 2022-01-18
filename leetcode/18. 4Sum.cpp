#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> twoSum(const vector<int>& nums, int target, size_t start) {
  vector<vector<int>> res;
  unordered_set<int> s;

  for (auto i = start; i < nums.size(); ++i) {
    if (res.empty() || res.back()[1] != nums[i]) {
      if (s.count(target - nums[i]) != 0) {
        res.push_back({ target - nums[i], nums[i] });
      }
    }
    s.insert(nums[i]);
  }

  return res;
}

vector<vector<int>> kSum(const vector<int>& nums, int target, size_t start, int k) {
  vector<vector<int>> res;

  if (start == nums.size()) {
    return res;
  }

  auto average_value = target / k;

  if (nums[start] > average_value || average_value > nums.back()) {
    return res;
  }

  if (k == 2) {
    return twoSum(nums, target, start);
  }

  for (auto i = start; i < nums.size(); ++i) {
    if (i == start || nums[i - 1] != nums[i]) {
      for (const auto& subset: kSum(nums, target - nums[i], i + 1, k - 1)) {
        res.emplace_back(begin(subset), end(subset));
        res.back().push_back(nums[i]);
      }
    }
  }

  return res;
}

vector<vector<int>> solve(vector<int>& nums, int target) {
  sort(begin(nums), end(nums));
  return kSum(nums, target, 0, 4);
}

int main() {
  vector<int> nums{ 1, 0, -1, 0, -2, 2 };
  solve(nums, 0);
  return 0;
}