#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n1 = s1.length(), n2 = s2.length();
  int C[n1 + 1][n2 + 1];
  for (int i = 0; i <= n1; i++) {
    for (int j = 0; j <= n2; j++) {
      if (i == 0 || j == 0)
        C[i][j] = 0;
      else if (s1[i - 1] == s2[j - 1])
        C[i][j] = C[i - 1][j - 1] + 1;
      else
        C[i][j] = max(C[i - 1][j], C[i][j - 1]);
    }
  }
  cout << C[n1][n2] << "\n";
  string ans;
  int i = n1, j = n2;
  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1])
      ans.push_back(s1[i - 1]), i--, j--;
    else if (C[i][j - 1] >= C[i - 1][j]) j--;
    else i--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;
  return 0;
}