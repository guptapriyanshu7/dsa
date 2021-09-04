#include <bits/stdc++.h>

using namespace std;


void recurse(int open, int close, int n, string s, vector<string>& ans) {
  if (s.size() == 2 * n) { ans.push_back(s); return; }
  if (open < n) recurse(open + 1, close, n, s + "(", ans);
  if (close < open) recurse(open, close + 1, n, s + ")", ans);
}

vector<string> solve(int n) {
  vector<string> ans;
  recurse(0, 0, n, "", ans);
  for (auto&& i : ans) {
    cout << i << " ";
  }
  return ans;
}

int main() {
  solve(3);
  return 0;
}