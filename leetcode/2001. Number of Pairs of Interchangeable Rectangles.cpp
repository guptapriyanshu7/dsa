#include <bits/stdc++.h>

using namespace std;

long long solve(vector<vector<int>>& rectangles) {
  long long cnt = 0;
  map<pair<int, int>, long long> mp;
  for (auto& rect : rectangles) {
    int gcd = __gcd(rect[0], rect[1]);
    pair<int, int> key = { rect[0] / gcd, rect[1] / gcd };
    if (mp.count(key)) cnt += mp[key];
    mp[key]++;
  }
  return cnt;
}

int main() {
  vector<vector<int>> nums{ {4,8},{3,6},{10,20},{15,30} };
  cout << solve(nums);
  return 0;
}