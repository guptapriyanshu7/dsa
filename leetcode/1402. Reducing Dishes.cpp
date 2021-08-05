#include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& A) {
  sort(A.begin(), A.end());
  int res = 0, total = 0, n = A.size();
  for (int i = n - 1; i >= 0 && total + A[i] > 0; --i) {
    total += A[i];
    res += total;
  }
  return res;
}

int main() {
  vector<int> satisfaction{ -7, 3, 4 };
  cout << solve(satisfaction);
  return 0;
}