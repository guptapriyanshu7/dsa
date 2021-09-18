#include <bits/stdc++.h>

using namespace std;

int recurse(int i, int n, vector<int>& memo) {
  if (i > n)
    return 0;
  if (memo[i] != -1)
    return memo[i];
  memo[i] = recurse(i + 2, n, memo) + recurse(i + 1, n, memo);
  return memo[i];
}

int solve(int n) {
  vector<int> memo(n + 1, -1);
  memo[n] = 1;
  return recurse(0, n, memo);
}

int main() {
  solve(3);
  return 0;
}