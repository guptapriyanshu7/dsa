#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>>& grid) {
  int row = grid.size(), col = grid[0].size();
  int islands = 0, neighbors = 0;
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      if(grid[i][j]) {
        islands++;
        if(i < row - 1 && grid[i + 1][j]) neighbors++;
        if(j < col - 1 && grid[i][j + 1]) neighbors++;
      }
    }
  }
  return islands * 4 - neighbors * 2;
}

int main() {
  vector<vector<int>> grid{ {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };
  cout << solve(grid);
  return 0;
}