#include <bits/stdc++.h>

using namespace std;

void recurse(vector<int>& temp, vector<int>& nums, vector<vector<int>>& res, int target, int pos) {
  if (target < 0) return;
  if (target == 0) {
    res.push_back(temp);
    return;
  }
  for (size_t j = pos; j < nums.size(); j++) {
    temp.push_back(nums[j]);
    recurse(temp, nums, res, target - nums[j], j);
    temp.erase(temp.end() - 1);
  }
}

vector<vector<int>> solve(vector<int>& nums, int target) {
  vector<vector<int>> res;
  vector<int> temp;
  recurse(temp, nums, res, target, 0);
  return res;
}

int main() {
  vector<int> nums{ 2, 3, 6, 7 };
  auto grid = solve(nums, 7);
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid[i].size(); j++)
      cout << grid[i][j] << " ";
    cout << "\n";
  }
  return 0;
}

/*
2 3 6 7, 7

2 2 2 2
2 2 3
2 2 6
.... 
*/