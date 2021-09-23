#include <bits/stdc++.h>

using namespace std;

void solve(vector<int>& a, int n, int k) {
  int m = INT_MIN;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      m = max(m, (i * j) - k * (a[i - 1] | a[j - 1]));
    }
  }
  cout << m << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (size_t i = 0; i < n; i++) {
      cin >> arr[i];
    }
    solve(arr, n, k);
  }
  return 0;
}