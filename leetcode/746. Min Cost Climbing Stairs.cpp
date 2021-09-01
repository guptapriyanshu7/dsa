#include <bits/stdc++.h>

using namespace std;

int recurse(int i, int n, vector<int>& memo, vector<int>& cost) {
  if (i >= n) return 0;
  if (memo[i] != -1) return memo[i];
  memo[i] = cost[i] + min(recurse(i + 2, n, memo, cost), recurse(i + 1, n, memo, cost));
  return memo[i];
}

int solve(vector<int>& cost) {
  auto n = cost.size();
  vector<int> memo(n + 1, -1);
  auto a = recurse(0, n, memo, cost);
  auto b = recurse(1, n, memo, cost);
  return min(a, b);
}

int main() {
  vector<int> cost{ 10,15,20 };
  cout << solve(cost);
  return 0;
}