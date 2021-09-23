#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  auto count = 0;
  for (size_t a = 1; a < n; a++) {
    for (size_t b = 1; b < n; b++) {
      auto c = sqrt(a * a + b * b);
      if (c <= n && floor(c) == c)
        count++;
    }
  }
  return count;
}

int main() {
  cout << solve(5);
  return 0;
}