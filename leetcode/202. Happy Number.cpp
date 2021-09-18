#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
  int sum = 0, rem;
  while (n != 0) {
    rem = n % 10;
    sum += rem * rem;
    n /= 10;
  }
  return sum;
}

int main() {
  int n          = 116;
  int slowRunner = n;
  int fastRunner = solve(n);
  while (fastRunner != 1 && slowRunner != fastRunner) {
    cout << slowRunner << " " << fastRunner << "\n";
    slowRunner = solve(slowRunner);
    fastRunner = solve(solve(fastRunner));
  }
  cout << slowRunner << " " << fastRunner << "\n";
  return 0;
}