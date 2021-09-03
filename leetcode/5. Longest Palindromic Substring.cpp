#include <bits/stdc++.h>

using namespace std;

string solve(string s) {
  string rev = s;
  reverse(rev.begin(), rev.end());
  int n = s.size(), maxlen = 0, ind = 0;
  vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if ((s[i - 1] == rev[j - 1])) {
        C[i][j] = C[i - 1][j - 1] + 1;
        if (C[i][j] > maxlen && i - C[i][j] == n - j) {
          maxlen = C[i][j];
          ind = i;
        }
      }
    }
  }
  return s.substr(ind - maxlen, maxlen);
}

int main() {
  cout << solve("cdgedc");
  return 0;
}