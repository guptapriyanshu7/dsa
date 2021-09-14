#include <bits/stdc++.h>

using namespace std;

void recurse(int pos, vector<int>& nums, vector<vector<int>>& res) {
  if (pos == nums.size()) res.push_back(nums);
  for (size_t j = pos; j < nums.size(); j++) {
    swap(nums[pos], nums[j]);
    recurse(pos + 1, nums, res);
    swap(nums[pos], nums[j]);
  }
}

vector<vector<int>> solve(vector<int>& nums) {
  vector<vector<int>> res;
  recurse(0, nums, res);
  return res;
}

int main() {
  vector<int> nums{ 1,2,3,4,5,6,7,8,9 };
  auto grid = solve(nums);
  int row = grid.size(), col = grid[0].size();
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++)
      cout << grid[i][j] << " ";
    cout << "\n";
  }
  return 0;
}

// 123 132 213...