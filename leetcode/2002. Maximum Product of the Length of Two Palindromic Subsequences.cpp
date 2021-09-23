#include <bits/stdc++.h>

using namespace std;

struct pair_hash {
  size_t operator()(pair<string, string> const& pair) const {
    return hash<string>()(pair.first + pair.second);
  }
};

size_t result = 0;
unordered_map<string, bool> dp;
unordered_set<pair<string, string>, pair_hash> uns;

bool isPalindrome(string s) {
  if (dp.count(s)) return dp[s];
  for (int i = 0; i < s.size() / 2; i++)
    if (s[i] != s[s.size() - i - 1])
      return dp[s] = false;
  return dp[s] = true;
}

void dfs(string& s, int i, string& s1, string& s2) {
  if (uns.count({ s2, s1 })) return;
  if (i == s.size()) {
    if (s1.size() == 0 || s2.size() == 0) return;
    cout << s1 << " " << s2 << "\n";
    uns.insert({ s1, s2 });
    if (isPalindrome(s1) && isPalindrome(s2))
      result = max(result, s1.size() * s2.size());
    return;
  }
  s1.push_back(s[i]);
  dfs(s, i + 1, s1, s2);
  s1.pop_back();

  s2.push_back(s[i]);
  dfs(s, i + 1, s1, s2);
  s2.pop_back();

  dfs(s, i + 1, s1, s2);
}

int solve(string s) {
  string s1 = "", s2 = "";
  dfs(s, 0, s1, s2);
  return result;
}

int main() {
  cout << solve("leetcodecom");
  return 0;
}