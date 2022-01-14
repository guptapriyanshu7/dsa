#include <bits/stdc++.h>

using namespace std;

int solve(int m, int n) {
  m--, n--;
  auto ans = 1L;
  if (n < m) swap(m, n);
  for (auto i = 0; i < m; i++) {
    ans *= m + n - i;
    ans /= i + 1;
  }
  return ans;
}

int main() {
  cout << solve(3, 7);
  return 0;
}