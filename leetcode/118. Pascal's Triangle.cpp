#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solve(int numRows) {
  vector<vector<int>> res(numRows);
  for (size_t i = 0; i < numRows; i++) {
    res[i].resize(i + 1);
    for (size_t j = 0; j <= i; j++) {
      if (j == 0 || j == i) res[i][j] = 1;
      else res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
    }
  }
  return res;
}

int main() {
  solve(5);
  return 0;
}
