#include <bits/stdc++.h>

using namespace std;

int solve(vector<string>& emails) {
  unordered_set<string> s;
  for (auto&& email : emails) {
    auto addPos = email.find('+'), atPos = email.find('@');
    if (addPos != string::npos && addPos < atPos) email.erase(addPos, atPos - addPos);
    atPos -= addPos + 1;
    for (size_t i = 0; i < atPos; i++)
      if (email[i] == '.')
        email.erase(i--, 1);
    cout << email << ",";
    s.insert(email);
  }
  return s.size();
}

int main() {
  vector<string> emails{ "test...e.mail++bob.cathy@leetcode.com" };
  solve(emails);
  return 0;
}