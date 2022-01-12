#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& mat) {
  vector<vector<int>> res;
  sort(mat.begin(), mat.end());
  res.push_back(mat[0]);
  for (const auto& m: mat) {
    if (auto& b = res.back(); b[1] >= m[0]) b[1] = max(b[1], m[1]);
    else res.push_back(m);
  }
  return res;
}

int main() {
  vector<vector<int>> intervals{ { 1, 3 }, { 2, 6 }, { 8, 10 }, { 15, 18 } };
  auto nums = merge(intervals);
  for (const auto& i: nums)
    cout << i[0] << "-" << i[1] << " ";
  return 0;
}