#include <bits/stdc++.h>

using namespace std;

double rec(double x, int n) {
  if (n == 1) return x;
  auto h = rec(x, n / 2);
  auto y = h * h;
  return n % 2 ? y * x : y;
}

double solve(double x, int n) {
  if (n == 0) return 1.0;
  if (n == INT_MIN) return 1 / rec(x, INT_MAX) * x;
  return n < 0 ? 1 / rec(x, abs(n)) : rec(x, n);
}

int main() {
  cout << solve(2.0, 3);
  return 0;
}