#include <bits/stdc++.h>

using namespace std;

string solve(string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  string ans = "";
  int i      = 0;
  char carry = '0';
  if (a.size() < b.size()) swap(a, b);
  while (i < a.size()) {
    if (i < b.size()) {
      if (a[i] == '0' && b[i] == '0')
        ans += carry, carry = '0';
      else if (a[i] == '1' && b[i] == '1')
        ans += carry, carry = '1';
      else
        ans += (carry == '0') ? '1' : '0';
    } else {
      if (a[i] == carry)
        ans += '0';
      else
        ans += '1', carry = '0';
    }
    i++;
  }
  if (carry == '1') ans += '1';
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  cout << solve("11", "0");
  return 0;
}