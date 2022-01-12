#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>>& grid) {
  size_t row = grid.size(), col = grid[0].size();
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      cout << grid[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

void solve(vector<vector<int>>& grid) {
  auto n = grid.size();
  for (size_t i = 0; i < n / 2; i++) {
    for (size_t j = 0; j < (n + 1) / 2; j++) {
      auto temp                  = grid[i][j];
      grid[i][j]                 = grid[n - 1 - j][i];
      grid[n - 1 - j][i]         = grid[n - 1 - i][n - 1 - j];
      grid[n - 1 - i][n - 1 - j] = grid[j][n - 1 - i];
      grid[j][n - 1 - i]         = temp;
      print(grid);
    }
  }
}

int main() {
  vector<vector<int>> nums{ { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
  print(nums);
  solve(nums);
  return 0;
}