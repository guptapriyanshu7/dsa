#include <bits/stdc++.h>

using namespace std;

int solve(string jewels, string stones) {
  int c = 0;
  unordered_set<char> s(jewels.begin(), jewels.end());
  for (auto&& ch : stones) {
    if (s.find(ch) != s.end()) {
      c++;
    }
  }
  return c;
}

int main() {
  cout << solve("aA", "aaAAbbCC");
  return 0;
}