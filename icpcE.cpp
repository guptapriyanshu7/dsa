#include <bits/stdc++.h>

using namespace std;

void solve(string s) {
  for (size_t i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'M' && s[i + 1] == '?') {
      cout << "Yes";
      return;
    }
  }
  for (size_t i = 0; i < s.size() - 1; i++) {
    if (s[i] == 'M' && s[i + 1] == 'U') {
      cout << "Yes";
      return;
    }
  }
  for (size_t i = s.size() - 1; i >= 1; i--) {
    if (s[i] == 'U' && s[i - 1] == '?') {
      cout << "Yes";
      return;
    }
  }
  cout << "No";
}

int main() {
  int t, total;
  cin >> t;
  total = t;
  while (t--) {
    // int size;
    // cin >> size;
    string s;
    cin >> s;
    // cout << "Case " << total - t << ": ";
    // vector<int> arr(size);
    // for (size_t i = 0; i < size; i++)
    //   cin >> arr[i];
    solve(s);
    cout << "\n";
  };
  return 0;
}