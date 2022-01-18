#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
  auto res = 0, i = 0, st = 0;
  unordered_map<char, int> m;
  while (i < s.size()) {
    if (m.count(s[i]) != 0) {
      res = max(res, i - st);
      st  = max(st, m[s[i]] + 1);
    }
    m[s[i]] = i;
    i++;
  }
  res = max(res, i - st);
  return res;
}

int main() {
  cout << solve("pwwkew");
  return 0;
}
