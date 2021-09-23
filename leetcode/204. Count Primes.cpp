#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  if (n == 0) return 0;
  vector<int> p(n + 1, true);
  p[0] = p[1] = false;
  for (size_t i = 2; i <= sqrt(n); i++) {
    if (p[i]) {
      for (size_t j = i * i; j <= n; j += i) {
        p[j] = false;
      }
    }
  }
  return count(p.begin(), p.end(), true);
}

int main() {
  cout << solve(10);
  return 0;
}