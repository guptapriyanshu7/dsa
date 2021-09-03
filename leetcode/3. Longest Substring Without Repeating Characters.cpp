#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
  unordered_map<char, int> m;
  int l = 0, i = 0, g = 0;
  while (i < s.size()) {
    if (m.count(s[i])) {
      g = max(g, i - l);
      l = max(l, m[s[i]] + 1);
    }
    m[s[i]] = i;
    i++;
  }
  g = max(g, i - l);
  return g;
}

int main() {
  cout << solve("abba");
  return 0;
}