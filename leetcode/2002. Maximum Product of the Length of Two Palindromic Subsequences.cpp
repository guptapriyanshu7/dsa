#include <bits/stdc++.h>

using namespace std;

int recurse(int l, int r, string s, vector<vector<int>>& dp) {
  if (l == r) return 1;
  if (l == r + 1) return 0;
  if (dp[l][r] != -1) return dp[l][r];
  return dp[l][r] = s[l] == s[r] ? 2 + recurse(l + 1, r - 1, s, dp)
    : max(recurse(l, r - 1, s, dp), recurse(l + 1, r, s, dp));
}

int lps(string s) {
  auto n = s.size();
  vector<vector<int>> dp(n, vector<int>(n, -1));
  return recurse(0, n - 1, s, dp);
}

int solve(string s) {
  int ans = 1, n = s.size();
  for (size_t i = 1; i < 1 << (n - 1); i++) {
    string s1 = "", s2 = "";
    for (size_t j = 0; j < n; j++) {
      if (i & (1 << j))
        s1.push_back(s[j]);
      else
        s2.push_back(s[j]);
    }
    ans = max(ans, lps(s1) * lps(s2));
  }
  return ans;
}

int main() {
  cout << solve("leetcodecom");
  return 0;
}