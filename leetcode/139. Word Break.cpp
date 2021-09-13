#include <bits/stdc++.h>

using namespace std;

bool recurse(string s, unordered_map<string, bool>& dict, unordered_map<string, bool>& memo) {
  if (dict.count(s)) return true;
  if (memo.count(s)) return memo[s];
  for (size_t i = 0; i < s.size(); i++) {
    string left = s.substr(0, i + 1), right = s.substr(i + 1);
    if (dict.count(left) && recurse(right, dict, memo)) return true;
  }
  return memo[s] = false;
}

bool solve(string s, vector<string>& wordDict) {
  unordered_map<string, bool> dict, memo;
  for (auto&& w : wordDict) dict[w] = true;
  return recurse(s, dict, memo);
}

int main() {
  vector<string> wordDict{ "leet","code" };
  cout << solve("leetcode", wordDict);
  return 0;
}
