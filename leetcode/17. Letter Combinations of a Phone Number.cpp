#include <bits/stdc++.h>

using namespace std;

void recurse(vector<string>& ans, string s, int i, string digits,
             vector<string> alphabets) {
  if (i == digits.size()) {
    ans.push_back(s);
    return;
  }
  for (auto&& ch: alphabets[digits[i] - '0'])
    recurse(ans, s + ch, i + 1, digits, alphabets);
}

vector<string> solve(string digits) {
  if (digits.size() == 0) return {};
  vector<string> ans;
  vector<string> alphabets = { "", "", "abc", "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz" };
  recurse(ans, "", 0, digits, alphabets);
  for (auto&& i: ans) std::cout << i << " ";
  return ans;
}

int main() {
  solve("22");
  return 0;
}