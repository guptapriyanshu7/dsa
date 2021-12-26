#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>>&& matrix) {
  auto row = matrix.size(), col = matrix[0].size();
  auto isCol = false;
  for (size_t i = 0; i < row; i++) {
    if (matrix[i][0] == 0) isCol = true;
    for (size_t j = 1; j < col; j++) {
      if (matrix[i][j] == 0) {
        matrix[0][j] = 0;
        matrix[i][0] = 0;
      }
    }
  }
  for (size_t i = 1; i < row; i++) {
    for (size_t j = 1; j < col; j++) {
      if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        matrix[i][j] = 0;
      }
    }
  }
  if (matrix[0][0] == 0) {
    for (size_t j = 0; j < col; j++)
      matrix[0][j] = 0;
  }
  if (isCol) {
    for (size_t i = 0; i < row; i++)
      matrix[i][0] = 0;
  }
}

int main() {
  solve({ { 0, 1, 2 }, { 1, 3, 4 } });
  return 0;
}
