#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
  if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;
  grid[i][j] = '#';
  dfs(grid, i + 1, j);
  dfs(grid, i - 1, j);
  dfs(grid, i, j + 1);
  dfs(grid, i, j - 1);
}

int solve(vector<vector<char>>& grid) {
  int count = 0;
  int row = grid.size(), col = grid[0].size();
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      if (grid[i][j] == '1') dfs(grid, i, j), count++;
    }
  }
  return count;
}

int main() {
  vector<vector<char>> grid{
    { '1', '1', '1', '1', '0' },
    { '1', '1', '0', '1', '0' },
    { '1', '1', '0', '0', '0' },
    { '0', '0', '0', '0', '0' }
  };
  cout << solve(grid);
  return 0;
}