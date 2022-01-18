#include <bits/stdc++.h>

using namespace std;

int merge(vector<int>& vec, size_t l, size_t m, size_t r) {
  auto i = l, j = m + 1, cnt = 0UL;

  while (i <= m) {
    while (j <= r && vec[i] > 2L * vec[j]) j++;
    cnt += j - (m + 1);
    i++;
  }

  vector<int> temp;
  i = l, j = m + 1;

  while (i <= m && j <= r) {
    if (vec[i] <= vec[j]) temp.push_back(vec[i++]);
    else temp.push_back(vec[j++]);
  }

  while (i <= m) temp.push_back(vec[i++]);

  while (j <= r) temp.push_back(vec[j++]);

  for (auto k = l; k <= r; ++k) vec[k] = temp[k - l];

  return cnt;
}

int solve(vector<int>& vec, size_t l, size_t r) {
  if (l >= r) return 0;
  auto mid = l + (r - l) / 2;
  return solve(vec, l, mid) + solve(vec, mid + 1, r) + merge(vec, l, mid, r);
}

int main() {
  vector<int> nums{ 1, 3, 2, 3, 1 };
  cout << solve(nums, 0, nums.size() - 1);
  return 0;
}