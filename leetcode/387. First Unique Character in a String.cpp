#include <bits/stdc++.h>

using namespace std;

int solve(string s) {
  unordered_map<char, int> m;
  for (auto&& c : s) m[c]++;
  for (size_t i = 0; i < s.size(); i++)
    if (m[s[i]] == 1)
      return i;
  return -1;
}

int main() {
  solve("leetcode");
  return 0;
}