#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& A, int B) {
  auto res = 0, xo = 0;
  unordered_map<int, int> mp;
  for (auto&& i: A) {
    xo ^= i;
    if (mp.count(xo ^ B) != 0)
      res += mp[xo ^ B];
    if (xo == B) res++;
    mp[xo]++;
  }
  return res;
}

int main() {
  vector<int> nums{ 4, 2, 2, 6, 4 };
  cout << solve(nums, 6);
  return 0;
}