#include <bits/stdc++.h>

using namespace std;

int recurse(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& dp) {
  if (dp[i][j] != -1) return dp[i][j];
  int m = 1;
  if (j < matrix[i].size() - 1 && matrix[i][j + 1] > matrix[i][j])
    m = max(m, 1 + recurse(matrix, i, j + 1, dp));
  if (i < matrix.size() - 1 && matrix[i + 1][j] > matrix[i][j])
    m = max(m, 1 + recurse(matrix, i + 1, j, dp));
  if (j > 0 && matrix[i][j - 1] > matrix[i][j])
    m = max(m, 1 + recurse(matrix, i, j - 1, dp));
  if (i > 0 && matrix[i - 1][j] > matrix[i][j])
    m = max(m, 1 + recurse(matrix, i - 1, j, dp));
  return dp[i][j] = m;
}

int solve(vector<vector<int>>& matrix) {
  vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
  int res = 0;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      if (dp[i][j] == -1) {
        res = max(res, recurse(matrix, i, j, dp));
      };
    }
  }
  return res;
}

int main() {
  vector<vector<int>> matrix{ { 3,4,5 }, { 3,2,6 }, { 2,2,1 } };
  cout << solve(matrix);
  return 0;
}