#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>>& grid, int row, int col, int empty, int& c) {
  if (!(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] >= 0)) return;
  if (grid[row][col] == 2) {
    if (empty == 0) c++;
    return;
  }
  grid[row][col] = -2;
  empty--;
  solve(grid, row, col + 1, empty, c);
  solve(grid, row, col - 1, empty, c);
  solve(grid, row + 1, col, empty, c);
  solve(grid, row - 1, col, empty, c);
  grid[row][col] = 0;
  empty++;
}

int main() {
  vector<vector<int>> grid{ { 1, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 2, -1 } };
  int x, y;
  auto empty = 1, c = 0;
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid[0].size(); j++) {
      if (grid[i][j] == 0) empty++;
      if (grid[i][j] == 1) x = i, y = j;
    }
  }
  solve(grid, x, y, empty, c);
  cout << c;
  return 0;
}