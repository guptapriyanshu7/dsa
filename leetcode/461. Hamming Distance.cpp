#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y) {
  int c = 0, n = x ^ y;
  while(n) {
    n &= (n - 1);
    c++;
  }
  return c;
}

int main() {
  cout << solve(3, 1);
  return 0;
}