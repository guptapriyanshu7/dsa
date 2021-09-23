#include <bits/stdc++.h>

using namespace std;

int recurse(string word1, string word2, int m, int n, vector<vector<int>>& dp) {
  int len1 = word1.size(), len2 = word2.size();
  if (m == word1.size()) return len2 - n;
  if (n == word2.size()) return len1 - m;
  if (dp[m][n] != -1) return dp[m][n];
  if (word1[m] == word2[n]) return dp[m][n] = recurse(word1, word2, m + 1, n + 1, dp);
  int insert      = recurse(word1, word2, m, n + 1, dp);
  int remove      = recurse(word1, word2, m + 1, n, dp);
  int dlt         = recurse(word1, word2, m + 1, n + 1, dp);
  return dp[m][n] = 1 + min(insert, min(remove, dlt));
}

int solve(string word1, string word2) {
  vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
  return recurse(word1, word2, 0, 0, dp);
}

int main() {
  cout << solve("intention", "execution");
  return 0;
}