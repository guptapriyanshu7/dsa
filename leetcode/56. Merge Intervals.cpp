#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& mat) {
  vector<vector<int>> res;
  sort(mat.begin(), mat.end());
  res.push_back(mat[0]);
  for (size_t i = 1; i < mat.size(); i++) {
    if (mat[i][0] <= res.back()[1])
      res.back()[1] = max(res.back()[1], mat[i][1]);
    else
      res.push_back(mat[i]);
  }
  for (auto&& v : res)
    cout << v[0] << " " << v[1] << "\n";
  return res;
}

int main() {
  vector<vector<int>> intervals{ { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
  merge(intervals);
  return 0;
}